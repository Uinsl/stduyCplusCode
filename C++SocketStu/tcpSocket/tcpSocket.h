#ifndef _TCPSOCKET_H_ //
#define _TCPSOCKET_H_ //

#include <WinSock2.h> //windos ƽ̨�������ͷ�ļ�
#pragma comment(lib,"ws2_32.lib") //���ļ�
#include <stdbool.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#define err(errMsg) printf("[line:%d]%s failed code %d",__LINE__,errMsg,WSAGetLastError())
// define ���庯����
// __LINE__?
// WSAGetLastError? Ĭ�Ϸ����㣿
// 

#define PORT 8888

//�������
bool initSocket();
//�ر������
bool closeSocket();
//����socket
SOCKET createServerSocket();

#endif //!_TCPSOCKET_H_  