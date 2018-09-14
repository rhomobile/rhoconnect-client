QT -= core

    equals(QT_MAJOR_VERSION, 5) {
        equals(QT_MINOR_VERSION, 6) {
            DEFINES += OS_SAILFISH OS_LINUX
            QT += core
        }
    }

TARGET = rhoconnect-client
TEMPLATE = lib

CONFIG += staticlib warn_on

isEmpty(RHODES_ROOT) {
  RHODES_ROOT = ../../../../../../rhodes
}

INCLUDEPATH += \
$$RHODES_ROOT/lib/commonAPI/coreapi/ext/shared\
$$RHODES_ROOT/platform/shared/common\
$$RHODES_ROOT/platform/shared/rubyext\
$$RHODES_ROOT/platform/shared/ruby/include\
$$RHODES_ROOT/platform/shared\
$$RHODES_ROOT/platform/shared/sync\
$$RHODES_ROOT/platform/shared\
../../shared\
../../shared/sync


macx {
  DESTDIR = $$RHODES_ROOT/platform/osx/bin/extensions
  OBJECTS_DIR = $$RHODES_ROOT/platform/osx/bin/extensions/rhoconnect-client
  INCLUDEPATH += $$RHODES_ROOT/platform/shared/ruby/iphone
}
win32 {
  DESTDIR = $$RHODES_ROOT/platform/win32/bin/extensions
  OBJECTS_DIR = $$RHODES_ROOT/platform/win32/bin/extensions/rhoconnect-client
  DEFINES += WIN32 _WINDOWS _LIB _UNICODE UNICODE WIN32_LEAN_AND_MEAN
  debug {
    DEFINES += _DEBUG DEBUG
  }
  release {
    DEFINES += _NDEBUG NDEBUG
  }
  INCLUDEPATH += $$RHODES_ROOT/platform/shared/ruby/win32
}

DEFINES += RHODES_QT_PLATFORM _XOPEN_SOURCE _DARWIN_C_SOURCE

!isEmpty(RHOSIMULATOR_BUILD) {
  DEFINES += RHODES_EMULATOR
}

!win32 {
  QMAKE_CFLAGS_WARN_ON += -Wno-extra -Wno-unused -Wno-sign-compare -Wno-format -Wno-parentheses
  QMAKE_CXXFLAGS_WARN_ON += -Wno-extra -Wno-unused -Wno-sign-compare -Wno-format -Wno-parentheses
  # QMAKE_CFLAGS += -fvisibility=hidden
  # QMAKE_CXXFLAGS += -fvisibility=hidden
  #QMAKE_CFLAGS_DEBUG -= -O2
  #QMAKE_CXXFLAGS_DEBUG -= -O2
}
win32 {
  QMAKE_CFLAGS_WARN_ON += /wd4996 /wd4100 /wd4005
  QMAKE_CXXFLAGS_WARN_ON += /wd4996 /wd4100 /wd4005
  QMAKE_CFLAGS_RELEASE += /O2
  QMAKE_CXXFLAGS_RELEASE += /O2
}

unix:!macx {
  OBJECTS_DIR = $$RHODES_ROOT/platform/linux/bin/extensions/rhoconnect-client
  INCLUDEPATH += $$RHODES_ROOT/platform/shared/ruby/sailfish


  contains(DEFINES, OS_LINUX)  {
      DESTDIR = $$RHODES_ROOT/platform/linux/bin/extensions
  }

  contains(DEFINES, OS_SAILFISH)  {
      INCLUDEPATH += $$RHODES_ROOT/platform/shared/qt/sailfish/src
      INCLUDEPATH += $$RHODES_ROOT/platform/shared/qt/sailfish
  }


  DEFINES += HAVE_CONFIG_H OS_LINUX
  QMAKE_CFLAGS += -fvisibility=hidden
  QMAKE_CXXFLAGS += -fvisibility=hidden

}


HEADERS += \
../../shared/RhoConnectClientImpl.h\
../../shared/RhoConnectClientSingletonImpl.h\
../../shared/generated/cpp/IRhoConnectClient.h\
../../shared/generated/cpp/RhoConnectClientBase.h\
../../shared/sync/ClientRegister.h\
../../shared/sync/ISyncProtocol.h\
../../shared/sync/SyncEngine.h\
../../shared/sync/SyncNotify.h\
../../shared/sync/SyncProtocol_3.h\
../../shared/sync/SyncProtocol_4.h\
../../shared/sync/SyncSource.h\
../../shared/sync/SyncThread.h

SOURCES += \
../../shared/RhoConnectClientImpl.cpp\
../../shared/initRhoconnectClient.cpp\
../../shared/rhoconnectclient.c\
../../shared/generated/rhoconnectclient_api_init.cpp\
../../shared/generated/rhoconnectclient_js_api.cpp\
../../shared/generated/rhoconnectclient_ruby_api.c\
../../shared/generated/cpp/RhoConnectClientBase.cpp\
../../shared/generated/cpp/RhoConnectClient_js_wrap.cpp\
../../shared/generated/cpp/RhoConnectClient_ruby_wrap.cpp\
../../shared/sync/ClientRegister.cpp\
../../shared/sync/SyncEngine.cpp\
../../shared/sync/SyncNotify.cpp\
../../shared/sync/SyncSource.cpp\
../../shared/sync/SyncThread.cpp
