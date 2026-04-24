#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	long long int v, m, t;
	scanf("%lld %lld %lld", &v, &m, & t);
	long long int x = 0, y = v;
	long long int arr[4];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = (v * m) % 10;
		v = (v * m) % 10;
	}
	long long int x_index = arr[0] - arr[2];
	long long int y_index = arr[3] - arr[1];
	
	if (t == 1)
	{
		printf("%lld %lld\n", x, y);
		return 0;
	}
	long long int nn = t - 1;
	long long int tmp = nn % 4;
	long long int mok = nn/ 4;
	x += (mok * x_index);
	y += (mok * y_index);
	if (tmp == 1)
	{
		x += arr[0];
	}
	else if (tmp == 2)
	{
		x += arr[0];
		y -= arr[1];
	}
	else if(tmp==3)
	{
		x += x_index;
		y -= arr[1];
	}
	printf("%lld %lld\n", x, y);
	return 0;
}