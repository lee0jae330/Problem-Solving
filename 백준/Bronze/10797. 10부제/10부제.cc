#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int day, count;
	count = 0;
	int n1, n2, n3, n4, n5;
	scanf("%d %d %d %d %d %d", &day, &n1, &n2, &n3, &n4, &n5);
	int a[] = { n1,n2,n3,n4,n5 };
	int n = sizeof(a)/sizeof(int);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == day)
		{
			count+=1;

		}
	}
	printf("%d\n", count);
}