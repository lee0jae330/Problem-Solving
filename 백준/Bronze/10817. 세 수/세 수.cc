#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	printf("%d\n", v[1]);
	return 0;
}