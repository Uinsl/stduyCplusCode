/*
* Ŀ¼
* ---------------------
* "const char *" ���͵�ֵ�������ڳ�ʼ�� "char" ���͵�ʵ��
* 
* inet_pton
* 
* 
* 
* 
* 
* 
* ---------------------
400 �ͷ�

"const char *" ���͵�ֵ�������ڳ�ʼ�� "char" ���͵�ʵ��
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
);inet_pton����
�����ʮ���ƴ�ת���������ֽ��������ֵ���˺�����IPv4��ַ��IPv6��ַ���ܴ���
��һ������������AF_INET��AF_INET6��
�ڶ���������һ��ָ����ʮ���ƴ���ָ�룺
������������һ��ָ��ת����������ֽ���Ķ�����ֵ��ָ��



struct in_addr s;
inet_pton(AF_INET,"",(void *)&s);











*/