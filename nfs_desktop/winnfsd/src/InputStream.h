#ifndef _INPUTSTREAM_H_
#define _INPUTSTREAM_H_

#include <stdio.h>

class IInputStream
{
    public:
    virtual ::u32 Read(void *pData, ::u32 nSize) = 0;
    virtual ::u32 Read(unsigned long *pnValue) = 0;
    virtual ::u32 Read8(unsigned __int64 *pnValue) = 0;
    virtual ::u32 Skip(::u32 nSize) = 0;
    virtual ::u32 GetSize(void) = 0;
};

#endif
