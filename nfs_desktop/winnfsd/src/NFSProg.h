#ifndef _NFSPROG_H_
#define _NFSPROG_H_

#include "RPCProg.h"
#include "NFS3Prog.h"

class CNFSProg : public CRPCProg
{
    public:
    CNFSProg(nfs * pnfs);
    ~CNFSProg();
    void SetUserID(::u32 nUID, ::u32 nGID);
    int Process(IInputStream *pInStream, IOutputStream *pOutStream, ProcessParam *pParam);
    void SetLogOn(bool bLogOn);

    private:
    ::u32 m_nUID, m_nGID;
    CNFS3Prog *m_pNFS3Prog;
};

#endif
