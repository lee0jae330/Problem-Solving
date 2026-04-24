#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<memory.h>

using namespace std;

int parent[1001];
bool check;
int result = 0;
int arr[1001][1001];
int visited[1001];
vector<pair<int, pair<int, int>>>v;
vector<pair<int, int>>tree[1001];

void bfs(int x)
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>>q;
	for (int i = 0; i < tree[x].size(); i++)
	{
		arr[x][tree[x][i].first] = tree[x][i].second;
		q.push({ tree[x][i].first,arr[x][tree[x][i].first] });
		visited[tree[x][i].first] = 1;
		
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int dist = q.front().second;
		q.pop();
		for (int i = 0; i < tree[y].size(); i++)
		{
			if (!visited[tree[y][i].first])
			{
				arr[x][tree[y][i].first] = max(dist, tree[y][i].second);
				q.push({ tree[y][i].first,arr[x][tree[y][i].first] });
				visited[tree[y][i].first] = 1;
			}
		}
	}
}

void init()
{
	for (int i = 0; i < 1001; i++)
		parent[i] = i;
}

int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	check = false;
	if (x != y)
	{
		check = true;
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
}

int main(void)
{
	init();
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		v.push_back({ cost,{a,b} });
	}
	sort(v.begin(), v.end());
	int num = 0;
	for (int j = 0; j < v.size(); j++)
	{
		merge(v[j].second.first, v[j].second.second);
		if (check)
		{
			num++;
			tree[v[j].second.first].push_back({ v[j].second.second,v[j].first });
			tree[v[j].second.second].push_back({ v[j].second.first,v[j].first });
			result += v[j].first;
		}
		if (num == N - 1)
			break;
	}
	for (int i = 1; i <= N; i++)
	{
		bfs(i);
	}
	
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		init();
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < b)
			printf("%d\n", result - arr[a][b]);
		else
			printf("%d\n", result - arr[b][a]);
	}
	return 0;
}