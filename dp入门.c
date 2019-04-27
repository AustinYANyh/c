#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void qipan(int arr[][50], int x, int y,int x2,int y2)
{
	int i = 0;
	int j = 0;
	for (i=1; i <= x; ++i)
	{
		for (j=1; j <= y; ++j)
		{

			if (i == x2&&j == y2)
			{
				continue;
			}
			if (i == 1 && j == 1)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			}
		}
	}
}

int main()
{
	int arr[][50] = { 0 };
	qipan(arr, 5, 5,3,3);
	printf("%d\n", arr[5][5]);

   system("pause");
   return 0;
}