#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a[4] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		int bae = 0, deung = 0;
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &a[j]);
			if (a[j] == 0)
				bae++;
			if (a[j] == 1)
				deung++;
		}
		if (bae == 0)
			printf("E\n");
		else if (bae == 1)
			printf("A\n");
		else if (bae == 2)
			printf("B\n");
		else if (bae == 3)
			printf("C\n");
		else
			printf("D\n");
	}
	return 0;
}