#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 	char str[] = "Hello";
// 	sizeof(str);
// 	strlen(str);
// 	printf("%d %d ", sizeof(str), strlen(str));


//��������ʹ����ȫ����λ��ż��ǰ�档

//��Ŀ��

// ����һ���������飬ʵ��һ��������
// �����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
// ����ż��λ������ĺ�벿��

void paixu(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{

			if (arr[i] % 2 == 0)
			{
				int tmp = { 0 };
				tmp = arr[i];
				arr[i] = arr[size - 1];
				arr[size - 1] = tmp;
				--size;
				--i;
			}
			else
			{
				continue;
			}
	}
}

// 	int arr[10] = {1,4,6,8,5,9,2,3,7,13};
// 	paixu(arr, 10);
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		printf("%d ", arr[i]);
// 	}


// ���Ͼ���
// ��һ����ά����.
// �����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
// �������������в���һ�������Ƿ���ڡ�
// ʱ�临�Ӷ�С��O(N);

#define maxhang 5
#define maxlie  5
int to_find(int arr[maxhang][maxlie], int hang, int lie, int n)
{
	//�ȸ����Ͻǵ�Ԫ�رȽ�(0��maxlie��)
	hang = 0;
	lie = maxlie - 1;
	while (hang<maxhang||lie>=0)
	{
			if (n > arr[hang][lie])
			{
				++hang;
			}
			else if (n < arr[hang][lie])
			{
				--lie;
			}
			else 
			{
				return 1;
			}
	}
	return 0;
}

int main()
{
	int arr[5][5] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 3, 6, 9, 12, 15, 4, 8, 12, 16, 20,  5, 10, 15,20,25 };
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j <5; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	int a = to_find(arr, 5, 5, 10);
	if (a == 1)
	{
		printf("�ҵ���!\n");
	}
	else
	{
		printf("û�ҵ�!\n");
	}
	system("pause");
   return 0;
}