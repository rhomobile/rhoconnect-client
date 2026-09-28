"""Compile the production bulk replacement boundary with bounded sync callback spies."""
import os
from pathlib import Path
import shutil
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]


@pytest.mark.parametrize("android", [False, True])
def test_bulk_replacement_error_does_not_report_success(tmp_path, android):
    source = (ROOT / "ext/rhoconnect-client/ext/shared/sync/SyncEngine.cpp").read_text()
    start = source.index('LOG(INFO) + "Bulk sync: start change db";')
    end = source.index("\nString CSyncEngine::makeBulkDataFileName", start)
    boundary = source[start:end]
    program = r'''
#include <cassert>
#include <string>
using String = std::string;
struct Logger { Logger operator+(const char*) { return {}; } };
#define LOG(level) Logger()
struct Errors { int ERR_NONE=0, ERR_UNEXPECTEDSERVERRESPONSE=4; } RhoAppAdapter;
struct Database {
    bool accept=false;
#ifdef OS_ANDROID
    bool setBulkSyncDB(String, String) { return accept; }
#else
    void setBulkSyncDB(String, String) {}
#endif
};
struct Options { int clears=0; void clearProperties() { ++clears; } };
struct Notify {
    int errors=0, successes=0;
    void fireBulkSyncNotification(bool, String stage, String, int error) {
        if (error) ++errors;
        if (stage == "ok") ++successes;
    }
};
struct Engine {
    Database dbPartition;
    Options options;
    Notify notify;
    String fDataName, strCryptKey, strPartition;
    int stops=0, metadata=0;
    void stopSync() { ++stops; }
    Notify& getNotify() { return notify; }
    Options& getSourceOptions() { return options; }
    void processServerSources(String) { ++metadata; }
    void change() {
''' + boundary + r'''
};
int main() {
    Engine rejected; rejected.change();
#ifdef OS_ANDROID
    assert(rejected.stops == 1 && rejected.notify.errors == 1);
    assert(rejected.notify.successes == 0 && rejected.options.clears == 0 && rejected.metadata == 0);
#else
    assert(rejected.stops == 0 && rejected.notify.successes == 1);
#endif
    Engine accepted; accepted.dbPartition.accept=true; accepted.change();
    assert(accepted.stops == 0 && accepted.notify.errors == 0 && accepted.notify.successes == 1);
    assert(accepted.options.clears == 1 && accepted.metadata == 1);
}
'''
    path = tmp_path / "boundary.cpp"
    path.write_text(program)
    cxx = os.environ.get("CXX") or shutil.which("g++") or "C:/ruby/msys64/ucrt64/bin/g++.exe"
    env = dict(os.environ, PATH=str(Path(cxx).parent) + os.pathsep + os.environ.get("PATH", ""))
    binary = tmp_path / ("boundary.exe" if os.name == "nt" else "boundary")
    command = [cxx, "-std=c++11", str(path), "-o", str(binary)]
    if android: command.append("-DOS_ANDROID")
    subprocess.run(command, env=env, check=True)
    subprocess.run([str(binary)], env=env, check=True)
