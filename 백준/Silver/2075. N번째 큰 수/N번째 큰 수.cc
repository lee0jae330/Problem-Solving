#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>>pq;

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			scanf("%d", &num);
			pq.push(num);
			if (pq.size() > N)
				pq.pop();
		}
	}
	printf("%d\n", pq.top());
	return 0;
}

