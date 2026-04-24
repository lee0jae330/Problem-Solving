#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;
vector<int>a;

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		a.push_back(num);
	}
	sort(v.begin(), v.end());
	sort(a.begin(), a.end());
	printf("%d\n", v[N - 1] + a[M - 1]);
	return 0;
}