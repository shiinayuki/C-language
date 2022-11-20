#include<stdio.h>
int main()
{
	int n,j,k,a[30];
	int i = 0;
	scanf("%d",&n);
	while(n > 0)
	{
		a[i++] = n % 10;
		n /= 10;
	}
	j = 0;
	k = i - 1;
	while(a[j] == a[k] && j <= i - 1) 
		{
		j++;
		k--;
	}
	if(j > i - 1)   
		printf("Yes");
	else
		printf("No");
	return 0;
}
