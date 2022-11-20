
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*2. 给出n个学生的考试成绩表，每条信息由姓名和分数组成，试设计一个算法：
(1)按分数高低次序，打印出每个学生在考试中获得的名次，分数相同的为同一名次；
(2)按名次列出每个学生的姓名与分数。
要求：
(1)学生的考试成绩表必须通过键盘输入数据而建立，同时要对输出进行格式控制。
(2)试用直接插入排序、希尔排序、快速排序算法实现对该问题的求解。
*/
int n;
typedef struct student{
	char num[20];
	char name[25];
	int score;	
}*Stu,StuNode;
 
void Build(Stu stu)
{
	FILE *fp;
	char name[20];
	int score,i;
	char num[20];
	fp=fopen("E:\\Student.txt","w");
	printf("请输入学生人数:");
	scanf("%d",&n);
 
	printf("请输入学生信息(学号，姓名，成绩)：\n");
	for(i=1;i<=n;i++)
	{
		scanf("%s %s %d",num,name,&score);
		fprintf(fp,"%s %s %d\n",num,name,score);
	}
	printf("登录成功.\n");
	fclose(fp);
}
void ReadFile(Stu &stu)
{//读文件，存到Stu结构体中 
	FILE *fp;
	int i;
	stu=(Stu)malloc(sizeof(StuNode)*(n+1));
	fp=fopen("E:\\Student.txt","r");
	for(i=1;i<=n;i++)
		fscanf(fp,"%s %s %d",stu[i].num,stu[i].name,&stu[i].score);
 
	fclose(fp);
}
 
void Display(Stu stu)
{//显示数据 
	int i;
	int temp=1,index=0;
	for(i=1;i<=n;i++)
	{
		printf("%2d %15s %15s %5d\n",temp,stu[i].num,stu[i].name,stu[i].score);
		if(i<n && stu[i].score==stu[i+1].score)
			index++;		
		else
		{
			temp+=index+1;
			index=0;
		}
	}
	
	free(stu);
}
 
void Swap(StuNode &a,StuNode &b)
{
	StuNode temp;
	temp=a;
	a=b;
	b=temp;
}
 
void InsertSort(Stu stu)
{//直接插入排序
	int i,j;
	int key;
	char name[20];
	char num[20];
	StuNode temp;
	stu=(Stu)malloc(sizeof(StuNode)*(n+1));
	ReadFile(stu);
	
	for(i=n;i>=1;i--)
	{
		temp=stu[i];
		j=i-1;
		while(j>=1 && temp.score> stu[j].score)
		{
			stu[j+1]=stu[j];
			j--;
		}
		j+=1;
		stu[j]=temp;
	}
	Display(stu);
}
 

int Partition(Stu stu,int low,int high)
{//快速排序--排序 
	int Pi;
	stu[0]=stu[low];
	
	Pi=stu[0].score;
	while(low<high)
	{
		while(low<high && stu[high].score<=Pi)
			high--;
		stu[low]=stu[high];
		while(low<high && stu[low].score>=Pi)
			low++;
		stu[high]=stu[low];
	}
	stu[low]=stu[0];
	return low;
}
void QuickSort(Stu stu,int low,int high)
{//快速排序--二分 
	int Pi;
	if(low<high)
	{
		Pi=Partition(stu,low,high);
		QuickSort(stu,low,Pi-1);
		QuickSort(stu,Pi+1,high);
	}
}

void Shellsort(Stu stu)    /*希尔排序*/
{
    int i,j,d;
    d=n/2;    /*确定固定增虽值*/
    while(d>=1)
    {
        for(i=d+1;i<=n;i++)    /*数组下标从d+1开始进行直接插入排序*/
        {
            s[0]=s[i];    /*设置监视哨*/
            j=i-d;    /*确定要进行比较的元素的最右边位置*/
            while((j>0)&&(s[0]<s[j]))
            {
                s[j+d]=s[j];    /*数据右移*/
                j=j-d;    /*向左移d个位置V*/
            }
            s[j + d]=s[0];    /*在确定的位罝插入s[i]*/
        }
        d = d/2;    /*增里变为原来的一半*/
    }
}
 

int main()
{
	Stu stu;
	int key;
	while(1)
	{
		printf("	----------------------\n");
		printf("	1.录入学生基本信息。\n");
		printf("	2.直接插入排序。\n");
		printf("	3.希尔排序。\n");
		printf("	4.快速排序。\n"); 
		printf("	5.输出学生信息。\n");
		printf("	6.退出。\n");
		printf("	----------------------\n");
		scanf("%d",&key);
				
		switch(key)
		{
			case 1:
				Build(stu);
				break;
			case 2:
				InsertSort(stu);
				break;
			case 3:
				Shellsort(stu);
				break;
			case 4:
				ReadFile(stu);
				QuickSort(stu,1,n);
				Display(stu);
				break;
			case 5:
				ReadFile(stu);
				Display(stu);
				break;
			default:
				return 0;
		}
	}
}
