#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VALUE 100000000
/*
秀水村是一个美丽的山村，可长期以来，村民们的房子都零散地分布在各个地方，没有道路直接相连，大家走动不便。
为了方便串门，村长决定带领大家修建道路连接各家各户。但由于修路要花很多钱（修的路越长，花费越多），
村里经费不足，因此村长召集大家一起商量，看怎么样修路花钱最少，还能把各家各户都连起来。
你现在就帮助村民们设计一下修路方案吧。
输入：输入文件road.in中，每一行为三个数a，b，c，分别表示房子a和房子b之间的距离为c（该文件请自己编写程序生成）。
输出：输出文件road.out中，每一行为三个数a，b，c，分别表示房子a和房子b之间是否可修路，c为1表示修路，为0表示不修路。
*/
int w[100][100],n;
int lowcost[100],closest[100];
bool s[100];
int max(int a,int b,int c){
int i = 0;
if(a>=b && a>=c)
{ 
i = a;
}
if(b>=a && b>=c) 
{
i = b;
}
if(c>=a && c>=b)
{ 
i = c;
}
return i;
}
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
memset(w,-1,sizeof(w));n = 0;
int a,b,c;scanf("%d%d%d",&a,&b,&c);
while(a!=0 && b!=0 && c!=0){
w[a][b] = w[b][a] = c;
n = max(n,a,b);
scanf("%d%d%d",&a,&b,&c);
}//读入
for(int i = 1;i<=n;i++)
for(int j = 1;j<=n;j++)
if(w[i][j]==-1)
w[i][j] = MAX_VALUE; //设MAX_VALUE为没有路的权
s[1] = true;
for(int i = 2;i<=n;i++){
lowcost[i] = w[1][i];
closest[i] = 1;
s[i] = false;
}
for(int i = 1;i<n;i++){
int min = MAX_VALUE;
int j = 1;
for(int k = 2;k<=n;k++)
{
if((lowcost[k]<min)&&(!s[k])){
min = lowcost[k];
j = k;
}
}
printf("%d %d\n",j,closest[j]);
s[j] = true;
for(int k = 2;k<=n;k++)
if((w[j][k]<lowcost[k])&&(!s[k])){
lowcost[k] = w[j][k];
closest[k] = j;
}
}
return 0;
}