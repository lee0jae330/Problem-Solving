#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

queue<int>q;
int visited[100002] = { 0, };
int time[100002] = { 0, };
int depth[100002];

int found = 0;
void bfs(int v, int target)
{
	visited[v] = 1;
	q.push(v);
	time[v] = 1;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		int tmp1, tmp2, tmp3;
		tmp1 = v - 1, tmp2 = v + 1, tmp3 = 2 * v;
		int arr[3] = { tmp1,tmp2,tmp3 };
		for (int i = 0; i < 3; i++)
		{
			int t = arr[i];
			if (t >= 0 && t < 100001)
			{
				if (!visited[t])
				{
					q.push(t);
					visited[t] = 1;
					time[t] = time[v];
					depth[t] = depth[v] + 1;
				}
				else if (depth[t] == depth[v] + 1)
					time[t] += time[v];
			}
			
		}
		
	}
}



int main(void)
{
	int N, K, count = 0;
	scanf("%d %d", &N, &K);
	bfs(N, K);
	printf("%d\n%d\n", depth[K], time[K]);
	return 0;
}