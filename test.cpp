typedef struct iphdr{                  //IPͷ
    unsigned int headlen:4;            //IPͷ����
    unsigned int version:4;            //IP�汾��
    unsigned char tos;                 //��������
    unsigned short id;                 //ID��
    unsigned short flag;               //���
    unsigned char ttl;                 //����ʱ��
    unsigned char prot;                //Э��
    unsigned short checksum;           //Ч���
    unsigned int sourceIP;             //ԴIP
    unsigned int destIP;               //Ŀ��IP
}IpHeader;
//IPͷ��  
typedef struct icmp_hdr             
{           
    unsigned char   icmp_type;   // ��Ϣ����            
    unsigned char   icmp_code;   // ����              
    unsigned short icmp_checksum; // У���            
// �����ǻ���ͷ           
    unsigned short icmp_id;   // ����Ωһ��ʶ�������ID�ţ�ͨ������Ϊ����ID            
    unsigned short icmp_sequence; // ���к�            
    unsigned long   icmp_timestamp; // ʱ���              
} ICMP_HDR, *PICMP_HDR;         
//����ԭʼ�׽���
    //AF_INET��ʾ��ַ��ΪIPV4
    //SOCK_RAW��ʾ������Ϊԭʼ�׽��֣�����UNIX/LINUX�����£�Ӧ�û��rootȨ�ޣ���Windows������ʹ�ù���ԱȨ�����г���
    SOCKET sRaw=::socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);    
SetTimeout(sRaw,1000,TRUE);     
//���ó�ʱʱ��
int SetTimeout(SOCKET s, int nTime, BOOL bRecv)             
{           
int ret = ::setsockopt(s, SOL_SOCKET,bRecv ? SO_RCVTIMEO : SO_SNDTIMEO,(char*)&nTime, sizeof(nTime));           
return ret != SOCKET_ERROR;             
}       
void change(int a,int b,int c,int d,char IP[20])          //IPת��            
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
//��ʼ��ICMP�����    
    pIcmp->icmp_type=8;  //��������         
    pIcmp->icmp_code=0;             
    pIcmp->icmp_id=(USHORT)::GetCurrentProcessId(); //����IDΪ��ǰ�̺߳�    
    pIcmp->icmp_checksum=0;  //�Ƚ�У�����0          
    pIcmp->icmp_sequence=0;  //���к�Ϊ0        
//���ICMP��           
    memset(&buff[sizeof(ICMP_HDR)],'E',32);  //��������     
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
    // ������              
    if(size)            
    {           
        cksum += *(UCHAR*)buff;             
    }           
    // ��32λ��chsum��16λ�͵�16λ��ӣ�Ȼ��ȡ��           
    cksum = (cksum >> 16) + (cksum & 0xffff);           
    cksum += (cksum >> 16);    // ???               
    return (USHORT)(~cksum);           
}  
//��дĿ�����������Ϣ������Ҫ��д�˿ںţ���ΪICMP�������Э��
    SOCKADDR_IN dest; 
    dest.sin_family=AF_INET;        
    dest.sin_port=htons(0);         
    dest.sin_addr.S_un.S_addr=inet_addr(szDestIP); //����������IP��ַ
 nRet=::sendto(sRaw,buff,sizeof(ICMP_HDR)+32,0,(SOCKADDR *)&dest,sizeof(dest)); 
nRet=::recvfrom(sRaw,revBuf,1024,0,(sockaddr *)&from,&nLen);            
        if (nRet==SOCKET_ERROR)             
        {  
        /*  if(WSAGetLastError()==WSAETIMEDOUT)
            {
                printf("Timed out.\n");
            }
            */
            printf("%s ����û�д�\n",szDestIP);            
            return -1;              
        }           
        printf("%s ������\n",szDestIP);              
        closesocket(nRet);              
    WSACleanup();   
int Computer(char szDestIP[30])                   //ɨ�������Ƿ���            
{           
    WSADATA wsaData;            
    WORD wVersionRequested=MAKEWORD(1,1);           
    if (WSAStartup(wVersionRequested , &wsaData))           
    {           
        printf("Winsock Initialization failed   \n");       
        exit(1);            
    }   
    //����ԭʼ�׽���
    //AF_INET��ʾ��ַ��ΪIPV4
    //SOCK_RAW��ʾ������Ϊԭʼ�׽��֣�����UNIX/LINUX�����£�Ӧ�û��rootȨ�ޣ���Windows������ʹ�ù���ԱȨ�����г���
    SOCKET sRaw=::socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);    
    SetTimeout(sRaw,1000,TRUE);             
    SOCKADDR_IN dest;  
    //��дĿ�����������Ϣ������Ҫ��д�˿ںţ���ΪICMP�������Э��
    dest.sin_family=AF_INET;        
    dest.sin_port=htons(0);         
    dest.sin_addr.S_un.S_addr=inet_addr(szDestIP);  

    //����ICMP���ݰ�
    char buff[sizeof(ICMP_HDR)+32];             
    ICMP_HDR * pIcmp=(ICMP_HDR *)buff;              
    //��ʼ��ICMP��  
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
        //���ICMP��
        pIcmp->icmp_checksum=0;             
        pIcmp->icmp_timestamp=::GetTickCount();             
        pIcmp->icmp_sequence=nSeq++;            
        pIcmp->icmp_checksum=checksum((USHORT *)buff,sizeof(ICMP_HDR)+32); 
        //��ʼ���ͺͽ���ICMP���
        nRet=::sendto(sRaw,buff,sizeof(ICMP_HDR)+32,0,(SOCKADDR *)&dest,sizeof(dest));              
        if (nRet==SOCKET_ERROR)             
        {           
            printf("sendto() failed:%d\n",::WSAGetLastError());             
            return -1;              
        }  
        //���ܻ��Իش�
        nRet=::recvfrom(sRaw,revBuf,1024,0,(sockaddr *)&from,&nLen);            
        if (nRet==SOCKET_ERROR)             
        {  
        /*  if(WSAGetLastError()==WSAETIMEDOUT)
            {
                printf("Timed out.\n");
            }
            */
            printf("%s ����û�д�\n",szDestIP);            
            return -1;              
        }           
        printf("%s ������\n",szDestIP);              
        closesocket(nRet);              
    WSACleanup();           
    return 0;           
}       
 for(int i=startport; i<=endport; i++)              
    {   
        //����һ��Socket        
        if((mysocket = socket(AF_INET, SOCK_STREAM,0)) == INVALID_SOCKET)  
            exit(1);            
        my_addr.sin_family = AF_INET; 

        //�����ֽ���ת��Ϊ�����ֽ���
        my_addr.sin_port = htons(i);    
        my_addr.sin_addr.s_addr = inet_addr(adr);  

        //�ô�Socket����Ŀ������
        if(connect(mysocket, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == SOCKET_ERROR)             
        { 
            //����ʧ��  
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
            printf("Port %d - �ر�\n", i);            
            closesocket(mysocket);  //�ر�Socket��������Դ         
        }           
        else            
        {  
            //���ӳɹ�
            pcount++;           
            printf("Port %d - ��\n", i);            
        }           
    printf("%d ports open on host - %s\n", pcount, adr);            
    closesocket(mysocket);              
    WSACleanup();               
    }  