#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int A, B;
	scanf("%d %d", &A, &B);
	int ax, ay,bx,by;
	switch (A % 4)
	{
	case 1:
		ax = 1;
		break;
	case 2:
		ax = 2;
		break;
	case 3:
		ax = 3;
		break;
	default:
		ax = 4;
	}
	switch (B % 4)
	{
	case 1:
		bx = 1;
		break;
	case 2:
		bx = 2;
		break;
	case 3:
		bx = 3;
		break;
	default:
		bx = 4;
	}
	int tmp = A / 4;
	if (tmp * 4 < A)
		ay = tmp + 1;
	else if (tmp * 4 == A)
		ay = tmp;
	tmp = B / 4;
	if (tmp * 4 < B)
		by = tmp + 1;
	else if (tmp * 4 == B)
		by = tmp;
	int d = abs(ax - bx) + abs(ay - by);
	printf("%d\n", d);
	return 0;
}