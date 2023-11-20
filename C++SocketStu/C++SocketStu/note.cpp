/*
* 目录
* ---------------------
* "const char *" 类型的值不能用于初始化 "char" 类型的实体
* 
* inet_pton
* 
* 
* 
* 
* 
* 
* ---------------------
400 油费

"const char *" 类型的值不能用于初始化 "char" 类型的实体
https://blog.csdn.net/weixin_44690935/article/details/108502989


https://blog.csdn.net/qq_39187019/article/details/92566355
service.sin_addr.s_addr = inet_pton(ip_inet);
inet_pton
inet_pton
(
    _In_                                      INT             Family,
    _In_                                      PCSTR           pszAddrString,
    _When_(Family == AF_INET, _Out_writes_bytes_(sizeof(IN_ADDR)))
    _When_(Family == AF_INET6, _Out_writes_bytes_(sizeof(IN6_ADDR)))
                                              PVOID           pAddrBuf
);inet_pton函数
将点分十进制串转换成网络字节序二进制值，此函数对IPv4地址和IPv6地址都能处理。
第一个参数可以是AF_INET或AF_INET6：
第二个参数是一个指向点分十进制串的指针：
第三个参数是一个指向转换后的网络字节序的二进制值的指针



struct in_addr s;
inet_pton(AF_INET,"",(void *)&s);











*/