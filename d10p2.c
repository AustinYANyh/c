#include<stdio.h>


int main()
{
	int murder;
	for (murder = 'a'; murder < 'e'; murder++)
	{
		if ((murder != 'a') + (murder == 'c') + (murder == 'd') + (murder != 'd') == 3)
			printf("%c������\n", murder);
	}

	system("pause");
	return 0;

}