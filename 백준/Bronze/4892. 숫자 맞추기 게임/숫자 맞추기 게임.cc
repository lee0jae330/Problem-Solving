#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{	int n0;
	int case1 = 1;
	while(1)
	{	
		scanf("%d", &n0);
		if (n0 == 0)
			break;
		int n1 = 3 * n0;
		int n2, n3, n4;
		if (n1 % 2 == 0)
		{
			n2 = n1 / 2;
			n3 = 3 * n2;
			n4 = n3 / 9;
			printf("%d. even %d\n", case1, n4);
		}
		else
		{
			n2 = (n1 + 1) / 2;
			n3 = 3 * n2;
			n4 = n3 / 9;
			printf("%d. odd %d\n", case1, n4);
		}
		case1++;
	}
	return 0;
}