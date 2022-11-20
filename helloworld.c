#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VALUE 100000000
int w[100][100],n;
int lowcost[100],closest[100];
int s[100];
int max(int a,int b,int c){
if(a>=b && a>=c) return a;
if(b>=a && b>=c) return b;
if(c>=a && c>=b) return c;
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
w[i][j] = MAX_VALUE; //凡是没有路的权都设MAX_VALUE
s[1] = 0;
for(int i = 2;i<=n;i++){
lowcost[i] = w[1][i];
closest[i] = 1;
s[i] = 1;
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
s[j] = 0;
for(int k = 2;k<=n;k++)
if((w[j][k]<lowcost[k])&&(!s[k])){
lowcost[k] = w[j][k];
closest[k] = j;
}
}
return 0;
}