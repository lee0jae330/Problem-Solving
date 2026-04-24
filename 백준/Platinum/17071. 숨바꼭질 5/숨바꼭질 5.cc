#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<string>

using namespace std;

queue<pair<int, int>>q;
int visited[2][500001] = { 0, };
int N, M;
int sum(int n)
{
	return n * (n + 1) / 2;
}

void bfs()
{
	int v = N;
	q.push({ v,0 });
	visited[0][v] = 0;
	memset(visited, -1, sizeof(visited));
	int depth;
	while (!q.empty())
	{
		v = q.front().first;
		depth = q.front().second;
		q.pop();
		if (v < 0 || v>500000)
			continue;
		if (visited[depth % 2][v] != -1)
			continue;
		visited[depth % 2][v] = depth;
		q.push({ v - 1,depth + 1 });
		q.push({ v + 1,depth + 1 });
		q.push({ 2 * v,depth + 1 });
	}

}


int main(void)
{
	scanf("%d %d", &N, &M);
	if (N == M)
	{
		printf("0\n");
		return 0;
	}
	memset(visited, -1, sizeof(visited));
	int v = N;
	q.push({ v,0 });
	visited[0][v] = 0;
	memset(visited, -1, sizeof(visited));
	int depth;
	while (!q.empty())
	{
		v = q.front().first;
		depth = q.front().second;
		q.pop();
		if (v < 0 || v>500000)
			continue;
		if (visited[depth % 2][v] != -1)
			continue;
		visited[depth % 2][v] = depth;
		q.push({ v - 1,depth + 1 });
		q.push({ v + 1,depth + 1 });
		q.push({ 2 * v,depth + 1 });
	}
	for (int i = 0; i <= 500000; i++)
	{
		int tmp = M + sum(i);
		if (tmp > 500000)
		{
			printf("-1\n");
			break;
		}
		if (visited[i % 2][tmp] != -1 && visited[i % 2][tmp] <= i)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}