#include <stdio.h>

void swap(int* x,int* y)
{
	int tmp;
	tmp = *x;
	*x  = *y;
	*y  = tmp;
}

void maopaopaixu(int arr[],int size)
{
	int bound = 0;//已排序区间[0,bound) 待排序区间[bound,size)
	for (int i = 0; i < size; ++i)
	{
		for (int j = size - 1; j>i; --j)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(&arr[j-1],&arr[j]);
			}
		}
	}

}


	//int arr[4] = { 9, 5, 2, 7 };
	//int size = sizeof(arr) /sizeof( arr[0]);
	//maopaopaixu(arr, size);
	//for (int i = 0; i < size; ++i)
	//{
	//	printf("%d\n", arr[i]);
	//}
	//int a = 4;
	//int b = 2;
	//printf("%x\n%x\n", a,b);


	//int a[4] = { 1, 2, 3, 4 };
	//int *ptr1 = (int *)(&a + 1);
	//int *ptr2 = (int *)((int)a + 1);
	//printf("%x,%x", ptr1[-1], *ptr2);
struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;

int main()
{
		printf("%p\n", p + 0x1);
		//printf("%p\n", (unsigned long)p + 0x1);
		//printf("%p\n", (unsigned int*)p + 0x1);
		return 0;
	system("pause");
return 0;
}
