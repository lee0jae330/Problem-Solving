#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>

using namespace std;

struct cmp
{
	bool operator()(int n1, int n2)
	{
		if (abs(n1) > abs(n2))
			return true;
		else if (abs(n1) == abs(n2))
		{
			if (n1 > n2)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int main(void)
{
	priority_queue<int, vector<int>, cmp>pq;
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