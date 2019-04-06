#include <stdio.h>

int main(){

	int a = 0;
	int b = 0;
	for (a = 1; a < 101; a++)
	{
		if (a % 10 == 9)
		{
			b++;
		}
		if (a / 10 == 9)
		{
			b++;
		}
	}
	printf("%d\n", b);
	system("pause");
	return 0;
}
