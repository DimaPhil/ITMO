package org.omg.CORBA_2_3;

class ORBImpl extends org.omg.CORBA_2_3.ORB {

    public ORBImpl() {
        super();
    }

    @Override
    public org.omg.CORBA.TypeCode create_alias_tc(java.lang.String x0, java.lang.String x1, org.omg.CORBA.TypeCode x2) {
        return null;
    }

    @Override
    public org.omg.CORBA.Any create_any() {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_array_tc(int x0, org.omg.CORBA.TypeCode x1) {
        return null;
    }

    @Override
    public org.omg.CORBA.ContextList create_context_list() {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_enum_tc(java.lang.String x0, java.lang.String x1, java.lang.String[] x2) {
        return null;
    }

    @Override
    public org.omg.CORBA.Environment create_environment() {
        return null;
    }

    @Override
    public org.omg.CORBA.ExceptionList create_exception_list() {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_exception_tc(java.lang.String x0, java.lang.String x1, org.omg.CORBA.StructMember[] x2) {
        return null;
    }

    private static org.omg.CORBA.ORB create_impl(java.lang.String x0) {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_interface_tc(java.lang.String x0, java.lang.String x1) {
        return null;
    }

    @Override
    public org.omg.CORBA.NVList create_list(int x0) {
        return null;
    }

    @Override
    public org.omg.CORBA.NamedValue create_named_value(java.lang.String x0, org.omg.CORBA.Any x1, int x2) {
        return null;
    }

    @Override
    public org.omg.CORBA.portable.OutputStream create_output_stream() {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_recursive_sequence_tc(int x0, int x1) {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_sequence_tc(int x0, org.omg.CORBA.TypeCode x1) {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_string_tc(int x0) {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_struct_tc(java.lang.String x0, java.lang.String x1, org.omg.CORBA.StructMember[] x2) {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_union_tc(java.lang.String x0, java.lang.String x1, org.omg.CORBA.TypeCode x2, org.omg.CORBA.UnionMember[] x3) {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode create_wstring_tc(int x0) {
        return null;
    }

    private static java.lang.String getPropertyFromFile(java.lang.String x0) {
        return null;
    }

    private static java.lang.String getSystemProperty(java.lang.String x0) {
        return null;
    }

    @Override
    public org.omg.CORBA.Context get_default_context() {
        return null;
    }

    @Override
    public org.omg.CORBA.Request get_next_response() throws org.omg.CORBA.WrongTransaction {
        return null;
    }

    @Override
    public org.omg.CORBA.TypeCode get_primitive_tc(org.omg.CORBA.TCKind x0) {
        return null;
    }

    public static synchronized org.omg.CORBA.ORB init() {
        return null;
    }

    public static org.omg.CORBA.ORB init(java.lang.String[] x0, java.util.Properties x1) {
        return null;
    }

    public static org.omg.CORBA.ORB init(java.applet.Applet x0, java.util.Properties x1) {
        return null;
    }

    @Override
    public java.lang.String[] list_initial_services() {
        return null;
    }

    @Override
    public java.lang.String object_to_string(org.omg.CORBA.Object x0) {
        return null;
    }

    @Override
    public boolean poll_next_response() {
        return false;
    }

    private static native void registerNatives();

    @Override
    public org.omg.CORBA.Object resolve_initial_references(java.lang.String x0) throws org.omg.CORBA.ORBPackage.InvalidName {
        return null;
    }

    @Override
    public void send_multiple_requests_deferred(org.omg.CORBA.Request[] x0) {
        return ;
    }

    @Override
    public void send_multiple_requests_oneway(org.omg.CORBA.Request[] x0) {
        return ;
    }

    @Override
    protected void set_parameters(java.lang.String[] x0, java.util.Properties x1) {
        return ;
    }

    @Override
    protected void set_parameters(java.applet.Applet x0, java.util.Properties x1) {
        return ;
    }

    @Override
    public org.omg.CORBA.Object string_to_object(java.lang.String x0) {
        return null;
    }


}
