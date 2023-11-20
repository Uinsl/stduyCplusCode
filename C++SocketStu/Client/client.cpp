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
    iResult = connect(ListenSocket, (SOCKADDR*)&service, sizeof(service));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"connect failed with error %u\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else
        wprintf(L"connect returned success\n");

    //5 发送接收消息
    int ret = 0;
    do {
        // 向客户端发送msg
        ret = send(ListenSocket, "I am Client", strlen("I am Client"), 0);
        // 接受客户端msg
        char buffer[64] = { '\0' };
        ret = recv(ListenSocket, buffer, 64, 0);
        printf("recv= %s\n", buffer);//?
    } while (ret != SOCKET_ERROR && ret != 0);

    closesocket(ListenSocket);
    WSACleanup();
    return 0;
}