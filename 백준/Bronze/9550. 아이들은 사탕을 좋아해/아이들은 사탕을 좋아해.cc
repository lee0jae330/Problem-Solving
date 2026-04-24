#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N, K, cnt = 0;
		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++)
		{
			int num;
			scanf("%d", &num);
			cnt += (num / K);
		}
		printf("%d\n", cnt);
	}
	return 0;
}