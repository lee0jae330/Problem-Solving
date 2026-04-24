#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		int num;
		double score = 0;
		int time = 0;
		scanf("%d", &num);
		getchar();
		int a;
		double b;
		for (int j = 0; j < num; j++)
		{
			scanf("%d %lf", &a, &b);
			time += a;
			b *= 10;
			int tmp = a * b;
			score += tmp;
		}
		score *= 10;
		score /= time;
		score /= 100;
		printf("%d %.1lf\n", time,score);
	}
	return 0;
}