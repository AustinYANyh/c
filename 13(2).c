#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>


#define Hang 3
#define Lie  3

int find(int arr[Hang][Lie],int hang,int lie, int n)
{
	if ((n<arr[0][0]) || (n>arr[hang - 1][lie - 1]))	//�Ϸ���У��
	return 0;	//���Ͼ����һ������С���һ�������	
	int a = 0;	int b = lie-1;
	while ((a < hang) && (b >= 0))
	{
		if (n>arr[a][b])		//���������ֱ���һ�е����д�,����һ�в���
		{
			a++;			
		}
		else if (n < arr[a][b])	//���������ֱ���һ�е�����С,��ǰ���в���	
		{	
			b--;
		}
		else	return 1;		//�����ҵ�
	}
	return 0;
}


int main()	
{
		int arr[3][3] = { 1, 3, 5, 2, 8, 10, 9, 15, 28 };
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		int x = 0;
		x = find(arr,3,3, 28);
		if (x == 1)
		{
			printf("�ҵ���!\n");
		}
		else if (x == 0)
			printf("û�ҵ�!\n");
		system("pause");
		return 0;
}
