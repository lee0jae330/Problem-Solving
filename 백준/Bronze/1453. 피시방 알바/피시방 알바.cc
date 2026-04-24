#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, person,no=0;
	int arr[100] = { 0, };
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &person);
		if (arr[person - 1] == 0)
			arr[person - 1] = 1;
		else
			no++;
	}
	printf("%d\n", no);
	return 0;
}