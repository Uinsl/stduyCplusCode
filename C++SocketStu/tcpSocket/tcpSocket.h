#ifndef _TCPSOCKET_H_ //
#define _TCPSOCKET_H_ //

#include <WinSock2.h> //windos 平台的网络库头文件
#pragma comment(lib,"ws2_32.lib") //库文件
#include <stdbool.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#define err(errMsg) printf("[line:%d]%s failed code %d",__LINE__,errMsg,WSAGetLastError())
// define 定义函数？
// __LINE__?
// WSAGetLastError? 默认返回零？
// 

#define PORT 8888

//打开网络库
bool initSocket();
//关闭网络库
bool closeSocket();
//创建socket
SOCKET createServerSocket();

#endif //!_TCPSOCKET_H_  