package javax.management.remote.rmi;

class RMIServerImplImpl extends javax.management.remote.rmi.RMIServerImpl {

    public RMIServerImplImpl(java.util.Map x0) {
        super(x0);
    }

    @Override
    protected void closeClient(javax.management.remote.rmi.RMIConnection x0) throws java.io.IOException {
        return ;
    }

    @Override
    protected void closeServer() throws java.io.IOException {
        return ;
    }

    @Override
    protected void export() throws java.io.IOException {
        return ;
    }

    @Override
    protected java.lang.String getProtocol() {
        return null;
    }

    @Override
    protected javax.management.remote.rmi.RMIConnection makeClient(java.lang.String x0, javax.security.auth.Subject x1) throws java.io.IOException {
        return null;
    }

    private static synchronized java.lang.String makeConnectionId(java.lang.String x0, javax.security.auth.Subject x1) {
        return null;
    }

    private static native void registerNatives();

    @Override
    public java.rmi.Remote toStub() throws java.io.IOException {
        return null;
    }


}
