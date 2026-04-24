#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int>v[100001];
int arr[100001];
int visited[100001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	stack<int>s;
	if (arr[0] != 1)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < v[arr[0]].size(); i++)
	{
		if (arr[1] == v[arr[0]][i])
		{
			s.push(arr[0]);
			visited[arr[0]] = 1;
		}
	}
	if (s.empty())
	{
		printf("0\n");
		return 0;
	}
	int num = 1;
	int idx = 1;
	while (!s.empty())
	{
		int top = s.top();
		int chk = arr[idx];
		visited[top] = 1;
		if (num == N)
		{
			printf("1\n");
			return 0;
		}
		if (binary_search(v[top].begin(), v[top].end(), chk))
		{
			s.push(chk);
			idx++;
			num++;
			continue;
		}
		s.pop();
	}
	printf("0\n");
	return 0;
}