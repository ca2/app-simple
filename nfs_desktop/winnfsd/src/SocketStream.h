#ifndef _SOCKETSTREAM_H_
#define _SOCKETSTREAM_H_

#include "InputStream.h"
#include "OutputStream.h"

class CSocketStream : public IInputStream, public IOutputStream
{
    public:
    CSocketStream();
    virtual ~CSocketStream();
    ::u8 *GetInput(void);
    void SetInputSize(::u32 nSize);
    ::u8 *GetOutput(void);
    ::u32 GetOutputSize(void);
    ::u32 GetBufferSize(void);
    ::u32 Read(void *pData, ::u32 nSize);
    ::u32 Read(unsigned long *pnValue);
    ::u32 Read8(unsigned __int64 *pnValue);
    ::u32 Skip(::u32 nSize);
    ::u32 GetSize(void);
    void Write(const void *pData, ::u32 nSize);
    void Write(unsigned long nValue);
    void Write8(unsigned __int64 nValue);
    void Seek(int nOffset, int nFrom);
    int GetPosition(void);
    void Reset(void);

    private:
    ::u8 *m_pInBuffer, *m_pOutBuffer;
    ::u32 m_nInBufferIndex, m_nInBufferSize, m_nOutBufferIndex, m_nOutBufferSize;
};

#endif
