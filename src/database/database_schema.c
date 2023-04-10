
const char *IpcDatabaseSchema =
        "CREATE TABLE parse_job ("
        "   id INTEGER PRIMARY KEY,"
        "   filepath TEXT NOT NULL,"
        "   mtime INTEGER NOT NULL,"
        "   st_size INTEGER NOT NULL"
        ");"
        ""
        "CREATE TABLE index_job ("
        "   id INTEGER PRIMARY KEY,"
        "   doc_id TEXT NOT NULL CHECK ( length(doc_id) = 32 ),"
        "   type INTEGER NOT NULL,"
        "   line TEXT"
        ");";

const char *IndexDatabaseSchema =
        "CREATE TABLE thumbnail ("
        "   id TEXT NOT NULL CHECK ( length(id) = 32 ),"
        "   num INTEGER NOT NULL,"
        "   data BLOB NOT NULL,"
        "   PRIMARY KEY(id, num)"
        ") WITHOUT ROWID;"
        ""
        "CREATE TABLE document ("
        "   id TEXT PRIMARY KEY CHECK ( length(id) = 32 ),"
        "   marked INTEGER NOT NULL DEFAULT (1),"
        "   mtime INTEGER NOT NULL,"
        "   size INTEGER NOT NULL,"
        "   json_data TEXT NOT NULL CHECK ( json_valid(json_data) )"
        ") WITHOUT ROWID;"
        ""
        "CREATE TABLE delete_list ("
        "   id TEXT PRIMARY KEY CHECK ( length(id) = 32 )"
        ") WITHOUT ROWID;"
        ""
        "CREATE TABLE tag ("
        "   id TEXT NOT NULL,"
        "   tag TEXT NOT NULL"
        ");"
        ""
        "CREATE TABLE document_sidecar ("
        "   id TEXT PRIMARY KEY NOT NULL,"
        "   json_data TEXT NOT NULL"
        ") WITHOUT ROWID;"
        ""
        "CREATE TABLE descriptor ("
        "   id TEXT NOT NULL,"
        "   version_major INTEGER NOT NULL,"
        "   version_minor INTEGER NOT NULL,"
        "   version_patch INTEGER NOT NULL,"
        "   root TEXT NOT NULL,"
        "   name TEXT NOT NULL,"
        "   rewrite_url TEXT,"
        "   timestamp INTEGER NOT NULL"
        ");"
        ""
        "CREATE TABLE stats_treemap ("
        "   path TEXT NOT NULL,"
        "   size INTEGER NOT NULL"
        ");"
        ""
        "CREATE TABLE stats_size_agg ("
        "   bucket INTEGER NOT NULL,"
        "   count INTEGER NOT NULL"
        ");"
        ""
        "CREATE TABLE stats_date_agg ("
        "   bucket INTEGER NOT NULL,"
        "   count INTEGER NOT NULL"
        ");"
        ""
        "CREATE TABLE stats_mime_agg ("
        "   mime TEXT NOT NULL,"
        "   size INTEGER NOT NULL,"
        "   count INTEGER NOT NULL"
        ");";
