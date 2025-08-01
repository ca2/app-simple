#ifndef _MOUNTPROG_H_
#define _MOUNTPROG_H_

#include "RPCProg.h"
//#include <map>
//#include <string>
#include "acme/prototype/collection/string_map.h"

#define MOUNT_NUM_MAX 100
#define MOUNT_PATH_MAX 100

enum pathFormats
{
	FORMAT_PATH = 1,
	FORMAT_PATHALIAS = 2
};

class CMountProg : public CRPCProg
{
    public:
    CMountProg(nfs * pnfs);
    virtual ~CMountProg();
	//bool SetPathFile(const_char_pointer  file);
    void Export(const_char_pointer  path, const_char_pointer  pathAlias);
	bool Refresh();
    char *GetClientAddr(int nIndex);
    int GetMountNumber(void);
    int Process(IInputStream *pInStream, IOutputStream *pOutStream, ProcessParam *pParam);
	//char *FormatPath(const_char_pointer  pPath, pathFormats format);

    protected:
    int m_nMountNum;
	//char *m_pPathFile;
	//std::map<::string, ::string> m_PathMap;
    string_to_string m_PathMap;
    char *m_pClientAddr[MOUNT_NUM_MAX];
    IInputStream *m_pInStream;
    IOutputStream *m_pOutStream;

    void ProcedureNULL(void);
    void ProcedureMNT(void);
    void ProcedureUMNT(void);
    void ProcedureUMNTALL(void);
    void ProcedureEXPORT(void);
    void ProcedureNOIMP(void);

    private:
    ProcessParam *m_pParam;
    int m_nResult;

	bool GetPath(::file::path & path);
   ::file::path GetPath(int &pathNumber);
	//bool ReadPathsFromFile(const_char_pointer  sFileName);
};

#endif
