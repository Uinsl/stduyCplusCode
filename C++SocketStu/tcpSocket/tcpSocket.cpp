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
	//������Socket
	// int af AF_INET=IPV4 AF_INET6=IPV6 
	// int
	SOCKET fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (fd == INVALID_SOCKET) 
	{
		err("createServerSocket");
		return INVALID_SOCKET;
	}

	//2��socket ��ip�Ͷ˿�
	struct sockaddr_in addr; //struct
	//const sockaddr_in seraddr;
	addr.sin_family = AF_INET; //fa AF_INET
	addr.sin_port = htons(PORT); //��˱����ֽ��� С��-�����ֽ��� 16λ TCP/UDP �˿ں�
	addr.sin_addr.S_un.S_addr = ADDR_ANY; 
	//inet_addr("127.0.0.1"); //.��ʮ����ת�� .�ֶ����Ƶĵ�ַ 32λIP��ַ
	//bind(fd, &addr, sizeof(addr));
	
	if ( SOCKET_ERROR == bind(fd, (SOCKADDR)&addr, sizeof(addr)))
	{
		err("bind");
		return false;
	}
	listen(fd, 10);

	return fd;
}




