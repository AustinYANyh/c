#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

//.��������ʹ����ȫ����λ��ż��ǰ�档 

//��Ŀ��

//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿��


void paixu(int arr[], int left , int right )
{
	for (int left= 0; left< right; ++left)
	{
		if (arr[left] % 2 == 0)
		{
			int tmp;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;//���ҵ������ż���ŵ�ĩβ
				right--;//ĩβ��ż������Ҫ��,���鳤�ȼ�ȥ1
				left--;//��λ��ԭĩβ��û�ж��Ƿ�Ϊż��
		}
		else continue;
	}

}
//int arr[] = { 0, 1, 3, 2, 8, 4, 9, 6 };
//int size = sizeof(arr) / sizeof(arr[0]);
//paixu(arr,0,7);
//for (int i = 0; i < size; ++i)
//{
//	printf("%d ", arr[i]);
//}


//1 3 5
//2 8 10 
//9 15 28

void paixu

int main11()
{
	int arr[3][3] = { 1,3,5,2,8,10,9,15,28 };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

   system("pause");
   return 0;
}
