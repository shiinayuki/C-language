#include <stdio.h>
#include <string.h>
/*
�� s ���ҳ���̵İ��� t �������ַ��������Ӵ�
*/
void subMatch(char s[100],char t[100])
{
	int i,n,k,j,l,o,a,p;
	k=strlen(s);
	o=n=strlen(t);
	//printf("a\n");
	for(;n<=k||a==1;n++)//���ڴ�С
	{

		for(i=0;i<k-n;i++)//�����ƶ�
			{//�����ڲ����
			    p=0;
				for(j=i;j<n;j++)
				{
					for(l=0;l<o;l++)
						if(t[l]==s[j])
							{
							    p++;//����������
                                printf("%d",p);
                                continue;
							}
				}
				if(p==o)
                {a=1;}
			}
		if(n==(k+1))
			{
			    printf("error!");
                return ;
			}
	}

	for(;i<k-n+1;i++)
	{
	    printf("%c",s[i]);
	}

}

int main()
{
    char s[100];
    char t[100];

    /*"XDOYEZODEYXNZ","XYZ"*/
    char c;
    int sn=0,tn=0;
    printf("���������ַ�����\n");
    scanf("%c",&c);

    while(1)
	{
        scanf("%c",&c);
        if(c=='"')
		{
            break;
        }
        else{
            s[sn++]=c;
        }
    }
    scanf("%c",&c);
    scanf("%c",&c);
    while(1)
	{
        scanf("%c",&c);
        if(c=='"')
		{
            break;
        }
        else
		{
            t[tn++]=c;
        }
    }


    //print
    printf("\"");
    subMatch(s,t);
	printf("\"\n");


    return 0;
}