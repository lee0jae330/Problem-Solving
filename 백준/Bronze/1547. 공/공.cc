#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[4] = { 0,1,2,3 };
void swap(int x, int y)
{
	int tmp;
	tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}
int main(void)
{
	int m,a,b;
	int n1 = 1, n2 = 2, n3 = 3;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		swap(a, b);
	}
	for (int i=0;i<4; i++)
	{
		if (arr[i] == 1)
		{
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}