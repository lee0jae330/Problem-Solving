#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int r, e, c;
		scanf("%d %d %d", &r, &e, &c);
		if (r < (e - c))
			printf("advertise\n");
		else if (r == (e - c))
			printf("does not matter\n");
		else
			printf("do not advertise\n");
	}
	return 0;
}