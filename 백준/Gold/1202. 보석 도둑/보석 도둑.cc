#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>


using namespace std;

vector<int>v;
pair<int, int>jewel[300001];
priority_queue<int>pq;

int main(void)
{
	int N, K;
	long long int result = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &jewel[i].first, &jewel[i].second);
	}
	for (int i = 0; i < K; i++)
	{
		int max_weight;
		scanf("%d", &max_weight);
		v.push_back(max_weight);
	}
	sort(jewel, jewel + N);
	sort(v.begin(), v.end());
	int index = 0;
	for (int i = 0; i < K; i++)
	{
		while (index < N && jewel[index].first <= v[i])
		{
			pq.push(jewel[index].second);
			index++;
		}
		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", result);
	return 0;
}