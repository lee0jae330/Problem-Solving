#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void)
{
	double a, b, c, d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	double result0 = a / c + b / d;
	double result1 = c / d + a / b;
	double result2 = d / b + c / a;
	double result3 = b / a + d / c;
	double sol = max(result0, result1);
	sol = max(sol, result2);
	sol = max(sol, result3);
	if (sol == result0)
		printf("0\n");
	else if (sol == result1)
		printf("1\n");
	else if (sol == result2)
		printf("2\n");
	else if (sol == result3)
		printf("3\n");
	return 0;
}