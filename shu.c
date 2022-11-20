#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,sum = 2;

	for(i = 1;i <= 100;i++)
	{
		for(j = 1;j < i-1 ;j++)
		{
			if(i % j == 0)
			{	
				printf("%d",i);
			}
			if(j >= i - 1)
			{
				break;
			}
		}
	}
	return 0;
}