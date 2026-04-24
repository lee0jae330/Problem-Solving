#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int A[10] = { 0, };
	int B[10] = { 0, };
	for (int i = 0; i < 10; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &B[i]);
	int A_point = 0, B_point = 0;
	char arr='a';
	for (int i = 0; i < 10; i++)
	{
		if (A[i] > B[i])
		{
			A_point += 3;
			arr = 'A';
		}
		else if (A[i] < B[i])
		{
			B_point += 3;
			arr = 'B';
		}
		else
		{
			A_point++;
			B_point++;
		}
	}
	printf("%d %d\n", A_point, B_point);
	if (A_point > B_point)
		printf("A\n");
	if (A_point < B_point)
		printf("B\n");
	if (A_point == 10 && B_point == 10)
		printf("D\n");
	if(A_point==B_point)
	{
		if (arr == 'A')
			printf("A\n");
		if (arr == 'B')
			printf("B\n");
	}
	return 0;
}