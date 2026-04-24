#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr[10001];
vector<int> visited;
vector<int> sum;

int MAX=0;
int COUNT = 0;

void dfs(int v)
{
	COUNT++;
	visited[v] = 1;
	for (int i = 0; i < arr[v].size(); i++)
	{
		if (visited[arr[v][i]] == 1)
			continue;
		visited[arr[v][i]] = 1;
		dfs(arr[v][i]);
	}
}


int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	int v1, v2;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &v1, &v2);
		arr[v2].push_back(v1);
	}

	sum = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		visited = vector<int>(N + 1, 0);
		dfs(i);
		sum[i] = COUNT;
		MAX = max(MAX, sum[i]);
		COUNT = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		if (sum[i] == MAX)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}