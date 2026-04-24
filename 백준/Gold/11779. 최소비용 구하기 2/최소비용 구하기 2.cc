#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>

#define INF 123456789

using namespace std;

int route[1001];
vector<pair<int, int>>path[1001];
int n, m;

vector<int> dijkstra(int start)
{
	vector<int> dist(1001, INF);
	dist[start] = 0;
	priority_queue < pair<int, int>>pq;
	pq.push({ 0,start });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)
			continue;
		for (int i = 0; i < path[cur].size(); i++)
		{
			int next = path[cur][i].first;
			int nextCost = cost + path[cur][i].second;
			
			if (dist[next] > nextCost)
			{
				route[next] = cur;
				dist[next] = nextCost;
				pq.push({ -nextCost,next });
			}
		}
	}
	return dist;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		path[start].push_back({ end,cost });
	}
	int start, end;
	scanf("%d %d", &start, &end);
	
	printf("%d\n", dijkstra(start)[end]);
	int cnt = 0;
	int tmp = end;
	stack<int>s;
	s.push(tmp);
	while (tmp != start)
	{
		cnt++;
		tmp = route[tmp];
		s.push(tmp);
	}
	printf("%d\n", cnt+1);
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}