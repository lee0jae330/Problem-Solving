#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

char str[1502];
int visited[1502][1502];
int N;
queue < pair<pair<int, int>, pair<int, char>>>q;
int sol = 0;
void bfs()
{
	int cnt;
	int s = 0;
	int e = strlen(str) - 1;
	if (str[s] == 'B' && str[e] == 'B')
	{
		q.push({ {s + 1,e},{1,'L'} });
		visited[s + 1][e] = 1;
		q.push({ {s,e - 1},{1,'L'} });
		visited[s][e - 1] = 1;
	}
	else if (str[s] == 'B')
	{
		q.push({ {s + 1,e},{1,'L'} });
		visited[s + 1][e] = 1;
	}
	else if (str[e] == 'B')
	{
		q.push({ {s,e - 1},{1,'L'} });
		visited[s][e - 1] = 1;
	}
	else
	{
		sol = max(sol, 0);
		return;
	}
	while (!q.empty())
	{
		s = q.front().first.first;
		e = q.front().first.second;
		cnt = q.front().second.first;
		char c = q.front().second.second;
		q.pop();
		if (s > e)
		{
			sol = max(sol, cnt);
			continue;
		}
		if (c == 'B')
		{
			if (str[s] == 'B' && str[e] == 'B')
			{
				if (!visited[s + 1][e])
				{
					q.push({ {s + 1,e},{cnt + 1,'L'} });
					visited[s + 1][e] = 1;
				}
				if (!visited[s][e - 1])
				{
					q.push({ {s,e - 1},{cnt + 1,'L'} });
					visited[s][e - 1] = 1;
				}
			}
			else if (str[s] == 'B')
			{
				if (!visited[s + 1][e])
				{
					q.push({ {s + 1,e},{cnt + 1,'L'} });
					visited[s + 1][e] = 1;
				}
			}
			else if (str[e] == 'B')
			{
				if (!visited[s][e - 1])
				{
					q.push({ {s,e - 1},{cnt + 1,'L'} });
					visited[s][e - 1] = 1;
				}
			}
			else
				sol = max(sol, cnt);

		}
		else if (c == 'L')
		{
			if (str[s] == 'L' && str[e] == 'L')
			{
				if (!visited[s + 1][e])
				{
					q.push({ {s + 1,e},{cnt + 1,'D'} });
					visited[s + 1][e] = 1;
				}
				if (!visited[s][e - 1])
				{
					q.push({ {s,e - 1},{cnt + 1,'D'} });
					visited[s][e - 1] = 1;
				}
			}
			else if (str[s] == 'L')
			{
				if (!visited[s + 1][e])
				{
					q.push({ {s + 1,e},{cnt + 1,'D'} });
					visited[s + 1][e] = 1;
				}
			}
			else if (str[e] == 'L')
			{
				if (!visited[s][e - 1])
				{
					q.push({ {s,e - 1},{cnt + 1,'D'} });
					visited[s][e - 1] = 1;
				}
			}
			else
				sol = max(sol, cnt);

		}
		else if (c == 'D')
		{
			if (str[s] == 'D' && str[e] == 'D')
			{
				if (!visited[s + 1][e])
				{
					q.push({ {s + 1,e},{cnt + 1,'B'} });
					visited[s + 1][e] = 1;
				}
				if (!visited[s][e - 1])
				{
					q.push({ {s,e - 1},{cnt + 1,'B'} });
					visited[s][e - 1] = 1;
				}
			}
			else if (str[s] == 'D')
			{
				if (!visited[s + 1][e])
				{
					q.push({ {s + 1,e},{cnt + 1,'B'} });
					visited[s + 1][e] = 1;
				}
			}
			else if (str[e] == 'D')
			{
				if (!visited[s][e - 1])
				{
					q.push({ {s,e - 1},{cnt + 1,'B'} });
					visited[s][e - 1] = 1;
				}
			}
			else
				sol = max(sol, cnt);

		}
	}
	sol = max(sol, cnt);
}

int main(void)
{
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < 3 * N; i++)
		scanf("%c", &str[i]);
	bfs();
	printf("%d\n", sol);
	return 0;
}