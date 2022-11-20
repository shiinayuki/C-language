typedef struct iphdr{                  //IP头
    unsigned int headlen:4;            //IP头长度
    unsigned int version:4;            //IP版本号
    unsigned char tos;                 //服务类型
    unsigned short id;                 //ID号
    unsigned short flag;               //标记
    unsigned char ttl;                 //生存时间
    unsigned char prot;                //协议
    unsigned short checksum;           //效验和
    unsigned int sourceIP;             //源IP
    unsigned int destIP;               //目的IP
}IpHeader;
//IP头部  
typedef struct icmp_hdr             
{           
    unsigned char   icmp_type;   // 消息类型            
    unsigned char   icmp_code;   // 代码              
    unsigned short icmp_checksum; // 校验和            
// 下面是回显头           
    unsigned short icmp_id;   // 用来惟一标识此请求的ID号，通常设置为进程ID            
    unsigned short icmp_sequence; // 序列号            
    unsigned long   icmp_timestamp; // 时间戳              
} ICMP_HDR, *PICMP_HDR;         
//创建原始套接字
    //AF_INET表示地址族为IPV4
    //SOCK_RAW表示创建的为原始套接字，若在UNIX/LINUX环境下，应该获得root权限，在Windows环境下使用管理员权限运行程序
    SOCKET sRaw=::socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);    
SetTimeout(sRaw,1000,TRUE);     
//设置超时时间
int SetTimeout(SOCKET s, int nTime, BOOL bRecv)             
{           
int ret = ::setsockopt(s, SOL_SOCKET,bRecv ? SO_RCVTIMEO : SO_SNDTIMEO,(char*)&nTime, sizeof(nTime));           
return ret != SOCKET_ERROR;             
}       
void change(int a,int b,int c,int d,char IP[20])          //IP转换            
{           
    char IPPort[4][4]={'\0'};           
    char temp[2]={'.','\0'};        
    itoa(a,IPPort[0],10);               
    itoa(b,IPPort[1],10);               
    itoa(c,IPPort[2],10);               
    itoa(d,IPPort[3],10);               
    strcat(IP,IPPort[0]);           
    strcat(IP,temp);            
    strcat(IP,IPPort[1]);           
    strcat(IP,temp);            
    strcat(IP,IPPort[2]);           
    strcat(IP,temp);            
    strcat(IP,IPPort[3]);           
}       
//初始化ICMP请求包    
    pIcmp->icmp_type=8;  //设置类型         
    pIcmp->icmp_code=0;             
    pIcmp->icmp_id=(USHORT)::GetCurrentProcessId(); //设置ID为当前线程号    
    pIcmp->icmp_checksum=0;  //先将校验和置0          
    pIcmp->icmp_sequence=0;  //序列号为0        
//填充ICMP包           
    memset(&buff[sizeof(ICMP_HDR)],'E',32);  //填入数据     
        pIcmp->icmp_checksum=0;             
    pIcmp->icmp_timestamp=::GetTickCount();             
    pIcmp->icmp_sequence=nSeq++;            
    pIcmp->icmp_checksum=checksum((USHORT *)buff,sizeof(ICMP_HDR)+32); 
USHORT checksum(USHORT* buff, int size)             
{           
    unsigned long cksum = 0;            
    while(size>1)           
    {           
        cksum += *buff++;           
        size -= sizeof(USHORT);             
    }           
    // 是奇数              
    if(size)            
    {           
        cksum += *(UCHAR*)buff;             
    }           
    // 将32位的chsum高16位和低16位相加，然后取反           
    cksum = (cksum >> 16) + (cksum & 0xffff);           
    cksum += (cksum >> 16);    // ???               
    return (USHORT)(~cksum);           
}  
//填写目的主机相关信息，不需要填写端口号，因为ICMP是网络层协议
    SOCKADDR_IN dest; 
    dest.sin_family=AF_INET;        
    dest.sin_port=htons(0);         
    dest.sin_addr.S_un.S_addr=inet_addr(szDestIP); //填入搜索的IP地址
 nRet=::sendto(sRaw,buff,sizeof(ICMP_HDR)+32,0,(SOCKADDR *)&dest,sizeof(dest)); 
nRet=::recvfrom(sRaw,revBuf,1024,0,(sockaddr *)&from,&nLen);            
        if (nRet==SOCKET_ERROR)             
        {  
        /*  if(WSAGetLastError()==WSAETIMEDOUT)
            {
                printf("Timed out.\n");
            }
            */
            printf("%s 主机没有存活！\n",szDestIP);            
            return -1;              
        }           
        printf("%s 主机存活！\n",szDestIP);              
        closesocket(nRet);              
    WSACleanup();   
int Computer(char szDestIP[30])                   //扫描主机是否存活            
{           
    WSADATA wsaData;            
    WORD wVersionRequested=MAKEWORD(1,1);           
    if (WSAStartup(wVersionRequested , &wsaData))           
    {           
        printf("Winsock Initialization failed   \n");       
        exit(1);            
    }   
    //创建原始套接字
    //AF_INET表示地址族为IPV4
    //SOCK_RAW表示创建的为原始套接字，若在UNIX/LINUX环境下，应该获得root权限，在Windows环境下使用管理员权限运行程序
    SOCKET sRaw=::socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);    
    SetTimeout(sRaw,1000,TRUE);             
    SOCKADDR_IN dest;  
    //填写目的主机相关信息，不需要填写端口号，因为ICMP是网络层协议
    dest.sin_family=AF_INET;        
    dest.sin_port=htons(0);         
    dest.sin_addr.S_un.S_addr=inet_addr(szDestIP);  

    //创建ICMP数据包
    char buff[sizeof(ICMP_HDR)+32];             
    ICMP_HDR * pIcmp=(ICMP_HDR *)buff;              
    //初始化ICMP包  
    pIcmp->icmp_type=8;             
    pIcmp->icmp_code=0;             
    pIcmp->icmp_id=(USHORT)::GetCurrentProcessId();             
    pIcmp->icmp_checksum=0;             
    pIcmp->icmp_sequence=0;             

    memset(&buff[sizeof(ICMP_HDR)],'E',32);             

    USHORT nSeq=0;              
    char revBuf[1024];              
    SOCKADDR_IN from;           
    int nLen=sizeof(from);              
        static int nCount=0;            
        int nRet;            
        //填充ICMP包
        pIcmp->icmp_checksum=0;             
        pIcmp->icmp_timestamp=::GetTickCount();             
        pIcmp->icmp_sequence=nSeq++;            
        pIcmp->icmp_checksum=checksum((USHORT *)buff,sizeof(ICMP_HDR)+32); 
        //开始发送和接受ICMP封包
        nRet=::sendto(sRaw,buff,sizeof(ICMP_HDR)+32,0,(SOCKADDR *)&dest,sizeof(dest));              
        if (nRet==SOCKET_ERROR)             
        {           
            printf("sendto() failed:%d\n",::WSAGetLastError());             
            return -1;              
        }  
        //接受回显回答
        nRet=::recvfrom(sRaw,revBuf,1024,0,(sockaddr *)&from,&nLen);            
        if (nRet==SOCKET_ERROR)             
        {  
        /*  if(WSAGetLastError()==WSAETIMEDOUT)
            {
                printf("Timed out.\n");
            }
            */
            printf("%s 主机没有存活！\n",szDestIP);            
            return -1;              
        }           
        printf("%s 主机存活！\n",szDestIP);              
        closesocket(nRet);              
    WSACleanup();           
    return 0;           
}       
 for(int i=startport; i<=endport; i++)              
    {   
        //创建一个Socket        
        if((mysocket = socket(AF_INET, SOCK_STREAM,0)) == INVALID_SOCKET)  
            exit(1);            
        my_addr.sin_family = AF_INET; 

        //主机字节序转换为网络字节序
        my_addr.sin_port = htons(i);    
        my_addr.sin_addr.s_addr = inet_addr(adr);  

        //用此Socket连接目的主机
        if(connect(mysocket, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == SOCKET_ERROR)             
        { 
            //连接失败  
        /*  switch(WSAGetLastError())
            {
            case 10060:
                printf("%s\t%d\tError\t\tConnection timed out\n",i);
                break;
            case 10061:
                printf("%s\t%d\tERROR%d\tConnection refused\n",i);
                break;
            default:
                printf("%s\t%d\tERROR\tCode:\n",WSAGetLastError());
                break;
            }*/
            printf("Port %d - 关闭\n", i);            
            closesocket(mysocket);  //关闭Socket，回收资源         
        }           
        else            
        {  
            //连接成功
            pcount++;           
            printf("Port %d - 打开\n", i);            
        }           
    printf("%d ports open on host - %s\n", pcount, adr);            
    closesocket(mysocket);              
    WSACleanup();               
    }  