#ifndef _NFS3PROG_H_
#define _NFS3PROG_H_

#include "RPCProg.h"
#include <string>
#include <windows.h>
#include <unordered_map>

#include "FileTable.h"
enum
{
   NFSPROC3_NULL = 0,
   NFSPROC3_GETATTR = 1,
   NFSPROC3_SETATTR = 2,
   NFSPROC3_LOOKUP = 3,
   NFSPROC3_ACCESS = 4,
   NFSPROC3_READLINK = 5,
   NFSPROC3_READ = 6,
   NFSPROC3_WRITE = 7,
   NFSPROC3_CREATE = 8,
   NFSPROC3_MKDIR = 9,
   NFSPROC3_SYMLINK = 10,
   NFSPROC3_MKNOD = 11,
   NFSPROC3_REMOVE = 12,
   NFSPROC3_RMDIR = 13,
   NFSPROC3_RENAME = 14,
   NFSPROC3_LINK = 15,
   NFSPROC3_READDIR = 16,
   NFSPROC3_READDIRPLUS = 17,
   NFSPROC3_FSSTAT = 18,
   NFSPROC3_FSINFO = 19,
   NFSPROC3_PATHCONF = 20,
   NFSPROC3_COMMIT = 21
};

enum
{
   NFS3_OK = 0,
   NFS3ERR_PERM = 1,
   NFS3ERR_NOENT = 2,
   NFS3ERR_IO = 5,
   NFS3ERR_NXIO = 6,
   NFS3ERR_ACCES = 13,
   NFS3ERR_EXIST = 17,
   NFS3ERR_XDEV = 18,
   NFS3ERR_NODEV = 19,
   NFS3ERR_NOTDIR = 20,
   NFS3ERR_ISDIR = 21,
   NFS3ERR_INVAL = 22,
   NFS3ERR_FBIG = 27,
   NFS3ERR_NOSPC = 28,
   NFS3ERR_ROFS = 30,
   NFS3ERR_MLINK = 31,
   NFS3ERR_NAMETOOLONG = 63,
   NFS3ERR_NOTEMPTY = 66,
   NFS3ERR_DQUOT = 69,
   NFS3ERR_STALE = 70,
   NFS3ERR_REMOTE = 71,
   NFS3ERR_BADHANDLE = 10001,
   NFS3ERR_NOT_SYNC = 10002,
   NFS3ERR_BAD_COOKIE = 10003,
   NFS3ERR_NOTSUPP = 10004,
   NFS3ERR_TOOSMALL = 10005,
   NFS3ERR_SERVERFAULT = 10006,
   NFS3ERR_BADTYPE = 10007,
   NFS3ERR_JUKEBOX = 10008
};

enum
{
   NF3REG = 1,
   NF3DIR = 2,
   NF3BLK = 3,
   NF3CHR = 4,
   NF3LNK = 5,
   NF3SOCK = 6,
   NF3FIFO = 7
};

enum
{
   ACCESS3_READ = 0x0001,
   ACCESS3_LOOKUP = 0x0002,
   ACCESS3_MODIFY = 0x0004,
   ACCESS3_EXTEND = 0x0008,
   ACCESS3_DELETE = 0x0010,
   ACCESS3_EXECUTE = 0x0020
};

enum
{
   FSF3_LINK = 0x0001,
   FSF3_SYMLINK = 0x0002,
   FSF3_HOMOGENEOUS = 0x0008,
   FSF3_CANSETTIME = 0x0010
};

enum
{
   UNSTABLE = 0,
   DATA_SYNC = 1,
   FILE_SYNC = 2
};

enum
{
   DONT_CHANGE = 0,
   SET_TO_SERVER_TIME = 1,
   SET_TO_CLIENT_TIME = 2
};

enum
{
   UNCHECKED = 0,
   GUARDED = 1,
   EXCLUSIVE = 2
};


typedef unsigned __int64 uint64;
typedef unsigned long uint32;
typedef long int32;
typedef uint64 fileid3;
typedef uint64 cookie3;
typedef uint32 uid3;
typedef uint32 gid3;
typedef uint64 size3;
typedef uint64 offset3;
typedef uint32 mode3;
typedef uint32 count3;
typedef uint32 nfsstat3;
typedef uint32 ftype3;
typedef uint32 stable_how;
typedef uint32 time_how;
typedef uint32 createmode3;
typedef uint64 cookieverf3;
typedef uint64 createverf3;
typedef uint64 writeverf3;

class opaque
{
    public:
    uint32 length;
    unsigned char *contents;

    opaque();
    opaque(uint32 len);
    virtual ~opaque();
    virtual void SetSize(uint32 len);
};

class nfs_fh3 : public opaque
{
    public:
    nfs_fh3();
    ~nfs_fh3();
};

class filename3 : public opaque
{
    public:
    char *name;

    filename3();
    ~filename3();
    void SetSize(uint32 len);
    void Set(const_char_pointer str);
};

class nfspath3 : public opaque
{
	public:
	char *path;

	nfspath3();
	~nfspath3();
	void SetSize(uint32 len);
    void Set(const ::file::path & path);
};

typedef struct
{
    uint32 specdata1;
    uint32 specdata2;
} specdata3;

typedef struct
{
    uint32 seconds;
    uint32 nseconds;
} nfstime3;

typedef struct
{
    bool check;
    nfstime3 obj_ctime;
} sattrguard3;

typedef struct
{
    ftype3 type;
    mode3 mode;
    uint32 nlink;
    uid3 uid;
    gid3 gid;
    size3 size;
    size3 used;
    specdata3 rdev;
    uint64 fsid;
    fileid3 fileid;
    nfstime3 atime;
    nfstime3 mtime;
    nfstime3 ctime;
} fattr3;

typedef struct
{
    bool attributes_follow;
    fattr3 attributes;
} post_op_attr;

typedef struct
{
    size3 size;
    nfstime3 mtime;
    nfstime3 ctime;
} wcc_attr;

typedef struct
{
    bool attributes_follow;
    wcc_attr attributes;
} pre_op_attr;

typedef struct
{
    pre_op_attr before;
    post_op_attr after;
} wcc_data;

typedef struct
{
    bool handle_follows;
    nfs_fh3 handle;
} post_op_fh3;

typedef struct
{
    bool set_it;
    mode3 mode;
} set_mode3;

typedef struct
{
    bool set_it;
    uid3 uid;
} set_uid3;

typedef struct
{
    bool set_it;
    gid3 gid;
} set_gid3;

typedef struct
{
    bool set_it;
    size3 size;
} set_size3;

typedef struct
{
    time_how set_it;
    nfstime3 atime;
} set_atime;

typedef struct
{
    time_how set_it;
    nfstime3 mtime;
} set_mtime;

typedef struct
{
    set_mode3 mode;
    set_uid3 uid;
    set_gid3 gid;
    set_size3 size;
    set_atime atime;
    set_mtime mtime;
} sattr3;

typedef struct
{
    nfs_fh3 dir;
    filename3 name;
} diropargs3;

typedef struct
{
    createmode3 mode;
    sattr3 obj_attributes;
    createverf3 verf;
} createhow3;

typedef struct 
{
	sattr3 symlink_attributes;
	nfspath3 symlink_data;
} symlinkdata3;

typedef struct _REPARSE_DATA_BUFFER {
	ULONG  ReparseTag;
	USHORT ReparseDataLength;
	USHORT Reserved;
	union {
		struct {
			USHORT SubstituteNameOffset;
			USHORT SubstituteNameLength;
			USHORT PrintNameOffset;
			USHORT PrintNameLength;
			ULONG  Flags;
			WCHAR  PathBuffer[1];
		} SymbolicLinkReparseBuffer;
		struct {
			USHORT SubstituteNameOffset;
			USHORT SubstituteNameLength;
			USHORT PrintNameOffset;
			USHORT PrintNameLength;
			WCHAR  PathBuffer[1];
		} MountPointReparseBuffer;
		struct {
			UCHAR DataBuffer[1];
		} GenericReparseBuffer;
	};
} REPARSE_DATA_BUFFER, *PREPARSE_DATA_BUFFER;

class CNFS3Prog : public CRPCProg
{
    public:
    CNFS3Prog(nfs * pnfs);
    ~CNFS3Prog();
    void SetUserID(unsigned int nUID, unsigned int nGID);
    int Process(IInputStream *pInStream, IOutputStream *pOutStream, ProcessParam *pParam);
    void RunCleanup();

    protected:
    unsigned long m_nUID, m_nGID;
    IInputStream *m_pInStream;
    IOutputStream *m_pOutStream;
    ProcessParam *m_pParam;
    unsigned int m_idThreadCleanup;
    HANDLE m_hThreadCleanup;
    ::pointer < ::mutex > m_pmutexCleanup;
    ::array < FILE_ITEM * > m_fileitemaCleanup;

    nfsstat3 ProcedureNULL(void);
    nfsstat3 ProcedureGETATTR(void);
    nfsstat3 ProcedureSETATTR(void);
    nfsstat3 ProcedureLOOKUP(void);
    nfsstat3 ProcedureACCESS(void);
    nfsstat3 ProcedureREADLINK(void);
    nfsstat3 ProcedureREAD(void);
    nfsstat3 ProcedureWRITE1(void);
    //nfsstat3 ProcedureWRITE(void);
    nfsstat3 ProcedureCREATE(void);
    nfsstat3 ProcedureMKDIR(void);
    nfsstat3 ProcedureSYMLINK(void);
    nfsstat3 ProcedureMKNOD(void);
    nfsstat3 ProcedureREMOVE(void);
    nfsstat3 ProcedureRMDIR(void);
    nfsstat3 ProcedureRENAME(void);
    nfsstat3 ProcedureLINK(void);
    nfsstat3 ProcedureREADDIR(void);
    nfsstat3 ProcedureREADDIRPLUS(void);
    nfsstat3 ProcedureFSSTAT(void);
    nfsstat3 ProcedureFSINFO(void);
    nfsstat3 ProcedurePATHCONF(void);
    nfsstat3 ProcedureCOMMIT(void);
    nfsstat3 ProcedureNOIMP(void);

    void Read(bool *pBool);
    void Read(uint32 *pUint32);
    void Read(uint64 *pUint64);
    void Read(sattr3 *pAttr);
    void Read(sattrguard3 *pGuard);
    void Read(diropargs3 *pDir);
    void Read(opaque *pOpaque);
    void Read(nfstime3 *pTime);
    void Read(createhow3 *pHow);
	void Read(symlinkdata3 *pSymlink);
    void Write(bool *pBool);
    void Write(uint32 *pUint32);
    void Write(uint64 *pUint64);
    void Write(fattr3 *pAttr);
    void Write(opaque *pOpaque);
    void Write(wcc_data *pWcc);
    void Write(post_op_attr *pAttr);
    void Write(pre_op_attr *pAttr);
    void Write(post_op_fh3 *pObj);
    void Write(nfstime3 *pTime);
    void Write(specdata3 *pSpec);
    void Write(wcc_attr *pAttr);

    private:
    int m_nResult;

    bool GetPath(::file::path &path);
    bool ReadDirectory(::file::path & dirName, ::string &fileName);
    char *GetFullPath(::string &dirName, ::string &fileName);
    nfsstat3 CheckFile(const_char_pointer fullPath);
    nfsstat3 CheckFile(const_char_pointer directory, const_char_pointer fullPath);
    bool GetFileHandle(const_char_pointer path, nfs_fh3 *pObject);
    bool GetUnstableFileAttributesForNFS(memory_file * pfile, const_char_pointer path, wcc_attr * pAttr);
    bool GetUnstableFileAttributesForNFS(memory_file * pfile, const_char_pointer path, fattr3 * pAttr);
    bool GetFileAttributesForNFS(const_char_pointer path, wcc_attr *pAttr);
    bool GetFileAttributesForNFS(const_char_pointer path, fattr3 *pAttr);
    bool GetFileAttributesForNFS(FILE * pfile, const_char_pointer path, wcc_attr * pAttr);
    bool GetFileAttributesForNFS(FILE * pfile, tree_path_item<FILE_ITEM> * pfileitem, const_char_pointer path, fattr3 * pAttr);
    UINT32 FileTimeToPOSIX(FILETIME ft);
    //std::unordered_map<int, FILE*> unstableStorageFile1;
    //std::unordered_map<int, ::pointer < memory_file >> unstableStorageFile;
};

#endif
