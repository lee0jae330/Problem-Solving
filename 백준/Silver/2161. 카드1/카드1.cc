#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[2002] = { 0, };
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		arr[i] = (i + 1);
	int input = 0;
	for (int i = 0; i < N; i++)
	{
		if (input == 0)
		{
			printf("%d ", arr[i]);
			input = 1;
		}
		else if (input == 1)
		{
			arr[N] = arr[i];
			input = 0;
			N++;
		}
	}
	printf("\n");
	return 0;
}