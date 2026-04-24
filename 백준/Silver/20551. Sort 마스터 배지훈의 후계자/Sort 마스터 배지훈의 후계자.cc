#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v1;
vector<int>v2;

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		v1.push_back(num);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		v2.push_back(num);
	}
	for (int i = 0; i < M; i++)
	{
		if (binary_search(v1.begin(), v1.end(), v2[i]))
		{
			printf("%d\n", lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin());
		}
		else
			printf("-1\n");
	}

	return 0;
}