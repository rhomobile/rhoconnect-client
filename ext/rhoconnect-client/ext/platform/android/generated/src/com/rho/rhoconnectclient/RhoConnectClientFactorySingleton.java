package com.rho.rhoconnectclient;

public class RhoConnectClientFactorySingleton {
    private static IRhoConnectClientFactory mFactory;
    public static void setInstance(IRhoConnectClientFactory factory) {
        mFactory = factory;
    }
    public static IRhoConnectClientFactory getInstance() {
        return mFactory;
    }
}
