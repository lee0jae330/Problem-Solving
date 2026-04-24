#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char name[30][15];
	int N;
	scanf("%d", &N);
	scanf("%s", name[0]);
	int increase = true, decrease = true;
	for (int i = 1; i < N; i++)
	{
		scanf("%s", name[i]);
		int tmp = strcmp(name[i - 1], name[i]);
		if (tmp > 0)
			increase = false;
		else if (tmp < 0)
			decrease = false;
	}
	if (increase)
		printf("INCREASING\n");
	else if (decrease)
		printf("DECREASING\n");
	else
		printf("NEITHER\n");
	return 0;
}