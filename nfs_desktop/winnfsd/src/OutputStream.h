#ifndef _OUTPUTSTREAM_H_
#define _OUTPUTSTREAM_H_

#include <stdio.h>

struct file_handle
{

   ::u64 m_ll = 0;

};


class IOutputStream
{
    public:
    virtual void Write(const void *pData, ::u32 nSize) = 0;
    virtual void Write(file_handle handle, ::u32 nSize)
    {
       if (nSize < sizeof(handle))
       {

          throw "what!!";
       }
       Write(&handle, sizeof(handle));
       ::i8 sz[64]{};
       nSize -= sizeof(handle);
       while (nSize > 0)
       {

          auto iWrite = minimum(nSize, sizeof(sz));

          Write(sz, iWrite);

          nSize -= iWrite;

       }

    }
    virtual void Write(unsigned long nValue) = 0;
    virtual void Write8(unsigned __int64 nValue) = 0;
    virtual void Seek(int nOffset, int nFrom) = 0;
    virtual int GetPosition(void) = 0;
};

#endif
