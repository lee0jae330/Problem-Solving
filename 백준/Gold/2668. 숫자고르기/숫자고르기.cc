#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int arr[102];
int visited[102];
int check[102];
vector<int>v;

void dfs(int x)
{
	visited[x] = 1;
	int next = arr[x];
	if (!visited[next])
		dfs(next);
	else if (!check[next])
	{
		for (int i = next; i != x; i = arr[i])
		{
			v.push_back(i);
		}
		v.push_back(x);
	}
	check[x] = 1;
	return;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}
	for (int i = 1; i <= N; i++)
		dfs(i);
	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
	return 0;
}