#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<algorithm>

using namespace std;

int ccw(pair<int, int>a, pair<int, int>b, pair<int, int>c) // s가 0보다 크면 반시계, 0보다 작으면 시계, 0이면 평행
{
	int s = a.first * b.second + b.first * c.second + c.first * a.second;
	s -= a.first * c.second + b.first * a.second + c.first * b.second;
	if (s > 0)
		return 1;
	else if (s== 0)
		return 0;
	return -1;
}


int main(void)
{
	pair<int, int>p[4];
	int a, b;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &a, &b);
		p[i].first = a, p[i].second = b;
	}
	if (ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]) == -1)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}