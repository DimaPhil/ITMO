package javax.sql.rowset;

class CachedRowSetImpl implements javax.sql.rowset.CachedRowSet {

    @Override
    public boolean absolute(int x0) throws java.sql.SQLException {
        return false;
    }

    @Override
    public void acceptChanges() throws javax.sql.rowset.spi.SyncProviderException {
        return ;
    }

    @Override
    public void acceptChanges(java.sql.Connection x0) throws javax.sql.rowset.spi.SyncProviderException {
        return ;
    }

    @Override
    public void addRowSetListener(javax.sql.RowSetListener x0) {
        return ;
    }

    @Override
    public void afterLast() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void beforeFirst() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void cancelRowUpdates() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void clearParameters() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void clearWarnings() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void close() throws java.sql.SQLException {
        return ;
    }

    @Override
    public boolean columnUpdated(int x0) throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean columnUpdated(java.lang.String x0) throws java.sql.SQLException {
        return false;
    }

    @Override
    public void commit() throws java.sql.SQLException {
        return ;
    }

    @Override
    public javax.sql.rowset.CachedRowSet createCopy() throws java.sql.SQLException {
        return null;
    }

    @Override
    public javax.sql.rowset.CachedRowSet createCopyNoConstraints() throws java.sql.SQLException {
        return null;
    }

    @Override
    public javax.sql.rowset.CachedRowSet createCopySchema() throws java.sql.SQLException {
        return null;
    }

    @Override
    public javax.sql.RowSet createShared() throws java.sql.SQLException {
        return null;
    }

    @Override
    public void deleteRow() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void execute() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void execute(java.sql.Connection x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public int findColumn(java.lang.String x0) throws java.sql.SQLException {
        return 0;
    }

    @Override
    public boolean first() throws java.sql.SQLException {
        return false;
    }

    @Override
    public java.sql.Array getArray(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Array getArray(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.InputStream getAsciiStream(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.InputStream getAsciiStream(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.math.BigDecimal getBigDecimal(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.math.BigDecimal getBigDecimal(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.math.BigDecimal getBigDecimal(int x0, int x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.math.BigDecimal getBigDecimal(java.lang.String x0, int x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.InputStream getBinaryStream(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.InputStream getBinaryStream(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Blob getBlob(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Blob getBlob(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public boolean getBoolean(int x0) throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean getBoolean(java.lang.String x0) throws java.sql.SQLException {
        return false;
    }

    @Override
    public byte getByte(int x0) throws java.sql.SQLException {
        return 0;
    }

    @Override
    public byte getByte(java.lang.String x0) throws java.sql.SQLException {
        return 0;
    }

    @Override
    public byte[] getBytes(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public byte[] getBytes(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.Reader getCharacterStream(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.Reader getCharacterStream(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Clob getClob(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Clob getClob(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getCommand() {
        return null;
    }

    @Override
    public int getConcurrency() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public java.lang.String getCursorName() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getDataSourceName() {
        return null;
    }

    @Override
    public java.sql.Date getDate(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Date getDate(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Date getDate(int x0, java.util.Calendar x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Date getDate(java.lang.String x0, java.util.Calendar x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public double getDouble(int x0) throws java.sql.SQLException {
        return 0.0d;
    }

    @Override
    public double getDouble(java.lang.String x0) throws java.sql.SQLException {
        return 0.0d;
    }

    @Override
    public boolean getEscapeProcessing() throws java.sql.SQLException {
        return false;
    }

    @Override
    public int getFetchDirection() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public int getFetchSize() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public float getFloat(int x0) throws java.sql.SQLException {
        return 0.0f;
    }

    @Override
    public float getFloat(java.lang.String x0) throws java.sql.SQLException {
        return 0.0f;
    }

    @Override
    public int getHoldability() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public int getInt(int x0) throws java.sql.SQLException {
        return 0;
    }

    @Override
    public int getInt(java.lang.String x0) throws java.sql.SQLException {
        return 0;
    }

    @Override
    public int[] getKeyColumns() throws java.sql.SQLException {
        return null;
    }

    @Override
    public long getLong(int x0) throws java.sql.SQLException {
        return 0L;
    }

    @Override
    public long getLong(java.lang.String x0) throws java.sql.SQLException {
        return 0L;
    }

    @Override
    public int[] getMatchColumnIndexes() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String[] getMatchColumnNames() throws java.sql.SQLException {
        return null;
    }

    @Override
    public int getMaxFieldSize() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public int getMaxRows() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public java.sql.ResultSetMetaData getMetaData() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.Reader getNCharacterStream(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.Reader getNCharacterStream(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.NClob getNClob(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.NClob getNClob(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getNString(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getNString(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.Object getObject(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.Object getObject(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.Object getObject(int x0, java.lang.Class x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.Object getObject(int x0, java.util.Map x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.Object getObject(java.lang.String x0, java.lang.Class x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.Object getObject(java.lang.String x0, java.util.Map x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.ResultSet getOriginal() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.ResultSet getOriginalRow() throws java.sql.SQLException {
        return null;
    }

    @Override
    public int getPageSize() {
        return 0;
    }

    @Override
    public java.lang.String getPassword() {
        return null;
    }

    @Override
    public int getQueryTimeout() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public java.sql.Ref getRef(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Ref getRef(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public int getRow() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public java.sql.RowId getRowId(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.RowId getRowId(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public javax.sql.rowset.RowSetWarning getRowSetWarnings() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.SQLXML getSQLXML(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.SQLXML getSQLXML(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public short getShort(int x0) throws java.sql.SQLException {
        return 0;
    }

    @Override
    public short getShort(java.lang.String x0) throws java.sql.SQLException {
        return 0;
    }

    @Override
    public boolean getShowDeleted() throws java.sql.SQLException {
        return false;
    }

    @Override
    public java.sql.Statement getStatement() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getString(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getString(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public javax.sql.rowset.spi.SyncProvider getSyncProvider() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getTableName() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Time getTime(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Time getTime(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Time getTime(int x0, java.util.Calendar x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Time getTime(java.lang.String x0, java.util.Calendar x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Timestamp getTimestamp(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Timestamp getTimestamp(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Timestamp getTimestamp(int x0, java.util.Calendar x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.sql.Timestamp getTimestamp(java.lang.String x0, java.util.Calendar x1) throws java.sql.SQLException {
        return null;
    }

    @Override
    public int getTransactionIsolation() {
        return 0;
    }

    @Override
    public int getType() throws java.sql.SQLException {
        return 0;
    }

    @Override
    public java.util.Map getTypeMap() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.net.URL getURL(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.net.URL getURL(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.InputStream getUnicodeStream(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.io.InputStream getUnicodeStream(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getUrl() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.lang.String getUsername() {
        return null;
    }

    @Override
    public java.sql.SQLWarning getWarnings() throws java.sql.SQLException {
        return null;
    }

    @Override
    public void insertRow() throws java.sql.SQLException {
        return ;
    }

    @Override
    public boolean isAfterLast() throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean isBeforeFirst() throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean isClosed() throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean isFirst() throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean isLast() throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean isReadOnly() {
        return false;
    }

    @Override
    public boolean isWrapperFor(java.lang.Class x0) throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean last() throws java.sql.SQLException {
        return false;
    }

    @Override
    public void moveToCurrentRow() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void moveToInsertRow() throws java.sql.SQLException {
        return ;
    }

    @Override
    public boolean next() throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean nextPage() throws java.sql.SQLException {
        return false;
    }

    @Override
    public void populate(java.sql.ResultSet x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void populate(java.sql.ResultSet x0, int x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public boolean previous() throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean previousPage() throws java.sql.SQLException {
        return false;
    }

    @Override
    public void refreshRow() throws java.sql.SQLException {
        return ;
    }

    @Override
    public boolean relative(int x0) throws java.sql.SQLException {
        return false;
    }

    @Override
    public void release() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void removeRowSetListener(javax.sql.RowSetListener x0) {
        return ;
    }

    @Override
    public void restoreOriginal() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void rollback() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void rollback(java.sql.Savepoint x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public boolean rowDeleted() throws java.sql.SQLException {
        return false;
    }

    @Override
    public boolean rowInserted() throws java.sql.SQLException {
        return false;
    }

    @Override
    public void rowSetPopulated(javax.sql.RowSetEvent x0, int x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public boolean rowUpdated() throws java.sql.SQLException {
        return false;
    }

    @Override
    public void setArray(int x0, java.sql.Array x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setAsciiStream(int x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setAsciiStream(java.lang.String x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setAsciiStream(int x0, java.io.InputStream x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setAsciiStream(java.lang.String x0, java.io.InputStream x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBigDecimal(int x0, java.math.BigDecimal x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBigDecimal(java.lang.String x0, java.math.BigDecimal x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBinaryStream(int x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBinaryStream(java.lang.String x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBinaryStream(int x0, java.io.InputStream x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBinaryStream(java.lang.String x0, java.io.InputStream x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBlob(int x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBlob(int x0, java.sql.Blob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBlob(java.lang.String x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBlob(java.lang.String x0, java.sql.Blob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBlob(int x0, java.io.InputStream x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBlob(java.lang.String x0, java.io.InputStream x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBoolean(int x0, boolean x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBoolean(java.lang.String x0, boolean x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setByte(int x0, byte x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setByte(java.lang.String x0, byte x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBytes(int x0, byte[] x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setBytes(java.lang.String x0, byte[] x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setCharacterStream(int x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setCharacterStream(java.lang.String x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setCharacterStream(int x0, java.io.Reader x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setCharacterStream(java.lang.String x0, java.io.Reader x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setClob(int x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setClob(int x0, java.sql.Clob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setClob(java.lang.String x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setClob(java.lang.String x0, java.sql.Clob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setClob(int x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setClob(java.lang.String x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setCommand(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setConcurrency(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setDataSourceName(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setDate(int x0, java.sql.Date x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setDate(java.lang.String x0, java.sql.Date x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setDate(int x0, java.sql.Date x1, java.util.Calendar x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setDate(java.lang.String x0, java.sql.Date x1, java.util.Calendar x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setDouble(int x0, double x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setDouble(java.lang.String x0, double x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setEscapeProcessing(boolean x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setFetchDirection(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setFetchSize(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setFloat(int x0, float x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setFloat(java.lang.String x0, float x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setInt(int x0, int x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setInt(java.lang.String x0, int x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setKeyColumns(int[] x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setLong(int x0, long x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setLong(java.lang.String x0, long x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setMatchColumn(int[] x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setMatchColumn(java.lang.String[] x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setMatchColumn(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setMatchColumn(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setMaxFieldSize(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setMaxRows(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setMetaData(javax.sql.RowSetMetaData x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNCharacterStream(int x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNCharacterStream(java.lang.String x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNCharacterStream(int x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNCharacterStream(java.lang.String x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNClob(int x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNClob(int x0, java.sql.NClob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNClob(java.lang.String x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNClob(java.lang.String x0, java.sql.NClob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNClob(int x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNClob(java.lang.String x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNString(int x0, java.lang.String x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNString(java.lang.String x0, java.lang.String x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNull(int x0, int x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNull(java.lang.String x0, int x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNull(int x0, int x1, java.lang.String x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setNull(java.lang.String x0, int x1, java.lang.String x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setObject(int x0, java.lang.Object x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setObject(java.lang.String x0, java.lang.Object x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setObject(int x0, java.lang.Object x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setObject(java.lang.String x0, java.lang.Object x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setObject(int x0, java.lang.Object x1, int x2, int x3) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setObject(java.lang.String x0, java.lang.Object x1, int x2, int x3) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setOriginalRow() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setPageSize(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setPassword(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setQueryTimeout(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setReadOnly(boolean x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setRef(int x0, java.sql.Ref x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setRowId(int x0, java.sql.RowId x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setRowId(java.lang.String x0, java.sql.RowId x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setSQLXML(int x0, java.sql.SQLXML x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setSQLXML(java.lang.String x0, java.sql.SQLXML x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setShort(int x0, short x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setShort(java.lang.String x0, short x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setShowDeleted(boolean x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setString(int x0, java.lang.String x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setString(java.lang.String x0, java.lang.String x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setSyncProvider(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTableName(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTime(int x0, java.sql.Time x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTime(java.lang.String x0, java.sql.Time x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTime(int x0, java.sql.Time x1, java.util.Calendar x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTime(java.lang.String x0, java.sql.Time x1, java.util.Calendar x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTimestamp(int x0, java.sql.Timestamp x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTimestamp(java.lang.String x0, java.sql.Timestamp x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTimestamp(int x0, java.sql.Timestamp x1, java.util.Calendar x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTimestamp(java.lang.String x0, java.sql.Timestamp x1, java.util.Calendar x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTransactionIsolation(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setType(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setTypeMap(java.util.Map x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setURL(int x0, java.net.URL x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setUrl(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void setUsername(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public int size() {
        return 0;
    }

    @Override
    public java.util.Collection toCollection() throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.util.Collection toCollection(int x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public java.util.Collection toCollection(java.lang.String x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public void undoDelete() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void undoInsert() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void undoUpdate() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void unsetMatchColumn(int[] x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void unsetMatchColumn(java.lang.String[] x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void unsetMatchColumn(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void unsetMatchColumn(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public java.lang.Object unwrap(java.lang.Class x0) throws java.sql.SQLException {
        return null;
    }

    @Override
    public void updateArray(int x0, java.sql.Array x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateArray(java.lang.String x0, java.sql.Array x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateAsciiStream(int x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateAsciiStream(java.lang.String x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateAsciiStream(int x0, java.io.InputStream x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateAsciiStream(int x0, java.io.InputStream x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateAsciiStream(java.lang.String x0, java.io.InputStream x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateAsciiStream(java.lang.String x0, java.io.InputStream x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBigDecimal(int x0, java.math.BigDecimal x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBigDecimal(java.lang.String x0, java.math.BigDecimal x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBinaryStream(int x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBinaryStream(java.lang.String x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBinaryStream(int x0, java.io.InputStream x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBinaryStream(int x0, java.io.InputStream x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBinaryStream(java.lang.String x0, java.io.InputStream x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBinaryStream(java.lang.String x0, java.io.InputStream x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBlob(int x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBlob(int x0, java.sql.Blob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBlob(java.lang.String x0, java.io.InputStream x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBlob(java.lang.String x0, java.sql.Blob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBlob(int x0, java.io.InputStream x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBlob(java.lang.String x0, java.io.InputStream x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBoolean(int x0, boolean x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBoolean(java.lang.String x0, boolean x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateByte(int x0, byte x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateByte(java.lang.String x0, byte x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBytes(int x0, byte[] x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateBytes(java.lang.String x0, byte[] x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateCharacterStream(int x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateCharacterStream(java.lang.String x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateCharacterStream(int x0, java.io.Reader x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateCharacterStream(int x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateCharacterStream(java.lang.String x0, java.io.Reader x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateCharacterStream(java.lang.String x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateClob(int x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateClob(int x0, java.sql.Clob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateClob(java.lang.String x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateClob(java.lang.String x0, java.sql.Clob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateClob(int x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateClob(java.lang.String x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateDate(int x0, java.sql.Date x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateDate(java.lang.String x0, java.sql.Date x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateDouble(int x0, double x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateDouble(java.lang.String x0, double x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateFloat(int x0, float x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateFloat(java.lang.String x0, float x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateInt(int x0, int x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateInt(java.lang.String x0, int x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateLong(int x0, long x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateLong(java.lang.String x0, long x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNCharacterStream(int x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNCharacterStream(java.lang.String x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNCharacterStream(int x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNCharacterStream(java.lang.String x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNClob(int x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNClob(int x0, java.sql.NClob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNClob(java.lang.String x0, java.io.Reader x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNClob(java.lang.String x0, java.sql.NClob x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNClob(int x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNClob(java.lang.String x0, java.io.Reader x1, long x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNString(int x0, java.lang.String x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNString(java.lang.String x0, java.lang.String x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNull(int x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateNull(java.lang.String x0) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateObject(int x0, java.lang.Object x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateObject(java.lang.String x0, java.lang.Object x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateObject(int x0, java.lang.Object x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateObject(java.lang.String x0, java.lang.Object x1, int x2) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateRef(int x0, java.sql.Ref x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateRef(java.lang.String x0, java.sql.Ref x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateRow() throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateRowId(int x0, java.sql.RowId x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateRowId(java.lang.String x0, java.sql.RowId x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateSQLXML(int x0, java.sql.SQLXML x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateSQLXML(java.lang.String x0, java.sql.SQLXML x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateShort(int x0, short x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateShort(java.lang.String x0, short x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateString(int x0, java.lang.String x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateString(java.lang.String x0, java.lang.String x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateTime(int x0, java.sql.Time x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateTime(java.lang.String x0, java.sql.Time x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateTimestamp(int x0, java.sql.Timestamp x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public void updateTimestamp(java.lang.String x0, java.sql.Timestamp x1) throws java.sql.SQLException {
        return ;
    }

    @Override
    public boolean wasNull() throws java.sql.SQLException {
        return false;
    }


}
