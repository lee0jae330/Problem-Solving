#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void)
{
	int N, W, H;
	scanf("%d %d %d", &N, &W, &H);
	int cross = sqrt(W * W + H * H);
	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		if (a <= H || a <= W || a <= cross)
			printf("DA\n");
		else
			printf("NE\n");
	}
	return 0;
}