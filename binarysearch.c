#define _CRT_SECURE_NO_WARNINGS 1
//折半查找法

//实现在主函数内部
#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0] - 1);//数组的下标是从0开始，所以要数组长度-1
	int key = 0;
	int mid = 0;
	printf("请输入你要查找的数字（1—10）：\n");
	scanf("%d", &key);
	while (left <= right)//当左下标小于等于右边进入循环
	{
		mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			break;
		}
	}
	if (left <= right)//循环结束后，当左下标<=右下标的时候，说明找到了
		printf("找到了，数字%d的下标是%d\n", arr[mid],mid);
	else//当左>右的时候，证明已经找了一遍，则数组中没有要找的元素
		printf("找不到%d\n",key);
	return 0;
}
