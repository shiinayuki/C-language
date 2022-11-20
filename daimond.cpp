#include

#include

#include

#include

#include

#include

#include

#include

#pragma comment(lib,"ws2_32.lib")

#define IPVER 4 //IP协议预定

#define MAX_BUFF_LEN 65500 //发送缓冲区最大值

typedef struct ip_hdr //定义IP首部

{

UCHAR h_verlen; //4位首部长度,4位IP版本号

UCHAR tos; //8位服务类型TOS