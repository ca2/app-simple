#ifndef _DATAGRAMSOCKET_H_
#define _DATAGRAMSOCKET_H_

#include "SocketListener.h"
#include "Socket.h"
#include <winsock.h>
class nfs;
class CDatagramSocket
{
    public:
       nfs * m_pnfs;
    CDatagramSocket(nfs *pnfs);
    ~CDatagramSocket();
    void SetListener(ISocketListener *pListener);
    bool Open(int nPort);
    void Close(void);
    int GetPort(void);
    void Run(void);

    private:
    int m_nPort;
    SOCKET m_Socket;
    CSocket *m_pSocket;
    bool m_bClosed;
    ISocketListener *m_pListener;
};

#endif
