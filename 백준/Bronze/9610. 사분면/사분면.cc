#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int x[1000] = { 0, };
	int y[1000] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);
	int Q1=0, Q2=0, Q3=0, Q4=0, AXIS=0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] > 0 && y[i] > 0)
			Q1++;
		else if (x[i] < 0 && y[i]>0)
			Q2++;
		else if (x[i] < 0 && y[i] < 0)
			Q3++;
		else if (x[i] > 0 && y[i] < 0)
			Q4++;
		else
			AXIS++;
	}
	printf("Q1: %d\n", Q1);
	printf("Q2: %d\n", Q2);
	printf("Q3: %d\n", Q3);
	printf("Q4: %d\n", Q4);
	printf("AXIS: %d\n", AXIS);
	return 0;
}