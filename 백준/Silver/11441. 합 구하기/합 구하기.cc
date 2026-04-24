#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[100005] = { 0, };
int main(void)
{
	int N, M,i,j,num;
	scanf("%d", &N);
	for (int i = 1; i < N + 1; i++)
	{
		scanf("%d", &num);
		arr[i] = arr[i - 1] + num;
	}
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", arr[j] - arr[i - 1]);
	}
	return 0;
}