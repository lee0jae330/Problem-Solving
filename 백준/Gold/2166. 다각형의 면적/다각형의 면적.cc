#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<double> x;
vector<double>y;

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		x.push_back(a);
		y.push_back(b);
	}
	x.push_back(x[0]);
	y.push_back(y[0]);
	double x_tmp = 0, y_tmp=0;

	for (int i = 0; i < N; i++)
		x_tmp += (x[i] * y[i + 1]);
	for (int i = 0; i < N; i++)
		y_tmp += (y[i] * x[i + 1]);
	double result = abs((x_tmp - y_tmp) / 2);
	result *= 10;
	floor(result);
	result /= 10;
	printf("%.1lf\n", result);
	return 0;
}