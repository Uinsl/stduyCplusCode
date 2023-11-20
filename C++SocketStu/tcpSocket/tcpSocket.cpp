#include "tcpSocket.h"

bool initSocket()
{
	WSADATA wsadata;
	//WSAStartup(MAKEWORD(2,2,),&wsadata);
	if (0 != WSAStartup(MAKEWORD(2, 2, ), &wsadata)) {
		//err(initSocket);
		return false;
	}
	return true;
}

bool closeSocket()
{
	if (0 != WSACleanup()) {			
		printf("WSACleanup err");
		return false;
	}

	return true;
}

SOCKET createServerSocket()
{
	//创建空Socket
	// int af AF_INET=IPV4 AF_INET6=IPV6 
	// int
	SOCKET fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (fd == INVALID_SOCKET) 
	{
		err("createServerSocket");
		return INVALID_SOCKET;
	}

	//2、socket 绑定ip和端口
	struct sockaddr_in addr; //struct
	//const sockaddr_in seraddr;
	addr.sin_family = AF_INET; //fa AF_INET
	addr.sin_port = htons(PORT); //大端本地字节序 小端-网络字节序 16位 TCP/UDP 端口号
	addr.sin_addr.S_un.S_addr = ADDR_ANY; 
	//inet_addr("127.0.0.1"); //.分十进制转成 .分二进制的地址 32位IP地址
	//bind(fd, &addr, sizeof(addr));
	
	if ( SOCKET_ERROR == bind(fd, (SOCKADDR)&addr, sizeof(addr)))
	{
		err("bind");
		return false;
	}
	listen(fd, 10);

	return fd;
}




