#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int main()
{

    // Declare some variables
    WSADATA wsaData;

    int iResult = 0;            // used to return function results

    // the listening socket to be created
    SOCKET ListenSocket = INVALID_SOCKET;

    // The socket address to be passed to bind
    sockaddr_in service;

    //----------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"Error at WSAStartup()\n");
        return 1;
    }
    //----------------------
    // Create a SOCKET for listening for 
    // incoming connection requests
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket function failed with error: %u\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port for the socket that is being bound.
    service.sin_family = AF_INET;
    //service.sin_addr.s_addr =
    inet_pton(AF_INET, "127.0.0.1", &service.sin_addr.s_addr);
    //inet_addr("127.0.0.1");

    service.sin_port = htons(27015);

    //----------------------
    // Bind the socket.
    iResult = bind(ListenSocket, (SOCKADDR*)&service, sizeof(service));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"bind failed with error %u\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else
        wprintf(L"bind returned success\n");

    //监听
    if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR)
        wprintf(L"listen function failed with error: %d\n", WSAGetLastError());

    wprintf(L"Listening on socket...\n");

    // 接受客户端的请求，并返回通讯服务器的套接字
    sockaddr_in addrClient;
    memset(&addrClient, 0, sizeof(sockaddr_in));//?
    int len = sizeof(sockaddr_in);
    //
    // 如果accept正常，则是有客户连接则返回一个表示连接的socket，
    // 没有客户连接则使进程睡眠直到有客户连接（即阻塞
    // 一直在监听？
    SOCKET c = accept(ListenSocket, (sockaddr*)&addrClient, &len);
    if (c == INVALID_SOCKET)
    {
        wprintf(L"accept failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else
        wprintf(L"Client connected.\n");

    //wprintf(L"Client connected.\n");

    //5 发送接收消息
    int ret = 0;
    do {
        // 向客户端发送msg
        ret = send(c, "I am Server", strlen("I am Server"), 0);
        // 接受客户端msg
        char buffer[64] = { '\0' };
        ret = recv(c, buffer, 64, 0);
        printf("recv= %s\n", buffer);//?

    } while (ret != SOCKET_ERROR && ret != 0);

    closesocket(ListenSocket);
    WSACleanup();
    return 0;
}