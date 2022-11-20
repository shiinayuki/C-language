#include <stdio.h>
int isprime(int n)
{
    for(int i=2;i*i<=n;i++)
   if(n%i==0)return 0;
 return n>1;  
}
int main()
{int n,i,sum;
 scanf("%d",&n);
 for(i=2;i<=n;i++)

   if(isprime(i))
   {
   printf("%d ",i);
   printf("\n");  
   }
 return 0;
}