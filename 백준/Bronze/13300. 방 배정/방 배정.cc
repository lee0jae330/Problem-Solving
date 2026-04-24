#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	int girl[6] = { 0, };
	int boy[6] = { 0, };
	int s, grade;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &s, &grade);
		if (s == 0)
			girl[grade - 1]++;
		else
			boy[grade - 1]++;
	}
	int g_sum = 0;
	for (int i = 0; i < 6; i++)
	{
		int count = 0;
		while (1)
		{
			if (girl[i] <= 0)
				break;
			girl[i] -= K;
			count++;
			
		}
		g_sum += count;
	}
	int b_sum = 0;
	for (int i = 0; i < 6; i++)
	{
		int count = 0;
		while (1)
		{
			if (boy[i] <= 0)
				break;
			boy[i] -= K;
			count++;
		}
		b_sum += count;
	}
	printf("%d\n", g_sum+b_sum);
	return 0;
}