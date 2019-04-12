#include<stdio.h>
#include <stdlib.h>


int chachong(int * player,int n)
{

	 int res = 0;
	 for (int i = 0; i < n; ++i)
	 {
		 res |= 1 << player[i];
	 }
	 return res == 00111110;
}
int main()
{
	//int murder;

	//for (murder = 'a'; murder < 'e'; murder++)

	//{

	//	if ((murder != 'a') + (murder == 'c') + (murder == 'd') + (murder != 'd') == 3)

	//		printf("%cÊÇÐ×ÊÖ\n", murder);

	//}

	int player[5] = { 0 };
	for ( player[0] = 1; player[0] <= 5; ++player[0])
	{
		for ( player[1] = 1; player[1] <= 5; ++player[1])
		{
			for ( player[2] = 1; player[2] <= 5; ++player[2])
			{
				for  (player[3] = 1; player[3] <= 5; ++player[3])
				{
					for ( player[4] = 1; player[4] <=5; ++player[4])
					{
						if ((player[0] == 3) + (player[1] == 2) == 1 &&

							(player[1] == 2) + (player[4] == 4) == 1 &&

							(player[2] == 1) + (player[3] == 2) == 1 &&

							(player[2] == 5) + (player[3] == 3) == 1 &&

							(player[4] == 4) + (player[0] == 1) == 1 &&

							chachong(player, 5))
						{
							printf("%d\n", player[0]);
							printf("%d\n", player[1]);
							printf("%d\n", player[2]);
							printf("%d\n", player[3]);
							printf("%d\n", player[4]);
							
						}
					}
				}
			}
		}
	}

	//int data[10][10] = { 0 };
	//printf("%d\n",data[0][0] = 1);
	//int i, j = 0;
	//for (i = 1; i < 10; ++i)
	//{
	//	printf("%d ",data[i][0] = 1);
	//	for ( j = 1; j < i; ++j)
	//	{
	//		printf("%d ",data[i][j]=data[i - 1][j - 1] + data[i - 1][j]);

	//	}
	//	printf("%d\n", data[i][j] = 1);
	//}


	system("pause");
   return 0;
}