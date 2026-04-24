#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	priority_queue<int, vector<int>, greater<int>>pq;
	int T, N;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		if (N == 0)
		{
			if (!pq.empty())
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			pq.push(N);
		}
	}
	return 0;
}