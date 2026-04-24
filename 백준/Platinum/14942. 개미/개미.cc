#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int visited[100001];
int energy[100001];
vector<pair<int, int>>v[100001];
vector<pair<int, int>>path;
int result[100001];
void dfs(int x)
{
	visited[x] = 1;
	if (x == 1)
	{
		result[x] = 1;
	}
	for (int i = 0; i < v[x].size(); i++)
	{
		int idx;
		if (!visited[v[x][i].first])
		{
			int cur = v[x][i].first;
			path.push_back({ x,v[x][i].second });
			idx = path.size() - 1;
			while (idx >= 0)
			{
				if (idx == 0)
				{
					if (energy[v[x][i].first] - path[idx].second >= 0)
					{
						result[v[x][i].first] = 1;
					}
					else
					{
						result[v[x][i].first] = cur;
					}
				}
				else
				{
					if (energy[v[x][i].first] - path[idx].second >= 0)
					{
						cur = path[idx].first;
						energy[v[x][i].first] -= path[idx].second;
					}
					else
					{
						result[v[x][i].first] = cur;
						break;
					}
				}
				idx--;
			}
			dfs(v[x][i].first);
		}
	}
	if(path.size()>0)
		path.pop_back();
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &energy[i]);
	}
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		v[a].push_back({ b,w });
		v[b].push_back({ a,w });
	}
	dfs(1);
	for (int i = 1; i <= N; i++)
	{
		printf("%d\n", result[i]);
	}
	return 0;
}