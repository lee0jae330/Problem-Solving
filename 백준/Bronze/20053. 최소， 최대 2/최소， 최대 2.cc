#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		v.clear();
		for (int j = 0; j < N; j++)
		{
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		printf("%d %d\n", v[0], v[v.size() - 1]);
	}
	return 0;
}