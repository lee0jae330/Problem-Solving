#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int a[999] = { 0, }, b[999] = { 0, }, c[999] = { 0, };
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	int price;
		if (a[0] == b[0] && b[0] == c[0])
			price = 10000 + 1000 * a[0];
		else if (a[0] != b[0] && b[0] != c[0] && c[0] != a[0])
		{
			int tmp = (a[0] > b[0]) ? a[0] : b[0];
			int maxnum = (tmp > c[0]) ? tmp : c[0];
			price = 100 * maxnum;
		}
		else
		{
			if (a[0] == b[0])
				price = 1000 + 100 * a[0];
			if (b[0] == c[0])
				price = 1000 + b[0] * 100;
			if (c[0] == a[0])
				price = 1000 + 100 * c[0];
		}
		int max = price;
		for (int i = 1; i < N; i++)
		{
			if (a[i] == b[i] && b[i] == c[i])
				price = 10000 + 1000 * a[i];
			else if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i])
			{
				int tmp = (a[i] > b[i]) ? a[i] : b[i];
				int maxnum = (tmp > c[i]) ? tmp : c[i];
				price = 100 * maxnum;
			}
			else
			{
				if (a[i] == b[i])
					price = 1000 + 100 * a[i];
				if (b[i] == c[i])
					price = 1000 + b[i] * 100;
				if (c[i] == a[i])
					price = 1000 + 100 * c[i];
			}
			int p_tmp = price;
			if (max < p_tmp)
				max = p_tmp;
		}
		printf("%d\n", max);
		return 0;
}