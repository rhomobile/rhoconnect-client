package com.rho.rhoconnectclient;

import com.rhomobile.rhodes.api.IRhoApiFactory;
import com.rhomobile.rhodes.api.IRhoApiSingletonFactory;

public interface IRhoConnectClientFactory
    extends IRhoApiFactory<IRhoConnectClient>,
            IRhoApiSingletonFactory<IRhoConnectClientSingleton> {

    @Override
    IRhoConnectClientSingleton getApiSingleton();

    @Override
    IRhoConnectClient getApiObject(String id);

}
