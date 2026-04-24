#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int student[100] = { 0, };
	int apple[100] = { 0, };
	for (int i = 0; i < N; i++)
		scanf("%d %d", &student[i], &apple[i]);
	int r_apple = 0;
	for (int i = 0; i < N; i++)
	{
		int num = apple[i] % student[i];
		r_apple += num;
	}
	printf("%d\n", r_apple);
	return 0;
}