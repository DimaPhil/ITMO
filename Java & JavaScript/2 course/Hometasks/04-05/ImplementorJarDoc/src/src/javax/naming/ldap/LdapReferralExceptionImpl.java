package javax.naming.ldap;

class LdapReferralExceptionImpl extends javax.naming.ldap.LdapReferralException {

    protected LdapReferralExceptionImpl() {
        super();
    }

    protected LdapReferralExceptionImpl(java.lang.String x0) {
        super(x0);
    }

    @Override
    public javax.naming.Context getReferralContext() throws javax.naming.NamingException {
        return null;
    }

    @Override
    public javax.naming.Context getReferralContext(java.util.Hashtable x0) throws javax.naming.NamingException {
        return null;
    }

    @Override
    public javax.naming.Context getReferralContext(java.util.Hashtable x0, javax.naming.ldap.Control[] x1) throws javax.naming.NamingException {
        return null;
    }

    @Override
    public java.lang.Object getReferralInfo() {
        return null;
    }

    private static native void registerNatives();

    @Override
    public void retryReferral() {
        return ;
    }

    @Override
    public boolean skipReferral() {
        return false;
    }


}
