#define _CRT_SECURE_NO_WARNINGS 1
//�۰���ҷ�

//ʵ�����������ڲ�
#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0] - 1);//������±��Ǵ�0��ʼ������Ҫ���鳤��-1
	int key = 0;
	int mid = 0;
	printf("��������Ҫ���ҵ����֣�1��10����\n");
	scanf("%d", &key);
	while (left <= right)//�����±�С�ڵ����ұ߽���ѭ��
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
	if (left <= right)//ѭ�������󣬵����±�<=���±��ʱ��˵���ҵ���
		printf("�ҵ��ˣ�����%d���±���%d\n", arr[mid],mid);
	else//����>�ҵ�ʱ��֤���Ѿ�����һ�飬��������û��Ҫ�ҵ�Ԫ��
		printf("�Ҳ���%d\n",key);
	return 0;
}
