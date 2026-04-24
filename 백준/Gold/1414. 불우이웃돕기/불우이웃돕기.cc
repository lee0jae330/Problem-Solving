#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int parent[101];
bool check;
int result;
vector<pair<int, pair<int, int>>>v;
char arr[102][102];

void init()
{
	for (int i = 0; i < 101; i++)
		parent[i] = i;
}

int find(int x)
{
	if (parent[x] == x)
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
	int sum=0;
	init();
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == '0')
				continue;
			else if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
			{
				num = arr[i][j] - 'a' + 1;
				v.push_back({ num,{i,j} });
			}
			else
			{
				num = arr[i][j] - 'A' + 27;
				v.push_back({ num,{i,j} });
			}
			sum += num;
		}
		getchar();
	}
	sort(v.begin(), v.end());
	int line = 0;
	for (int i = 0; i < v.size(); i++)
	{
		merge(v[i].second.first, v[i].second.second);
		if (check)
		{
			result += v[i].first;
			line++;
		}
	}
	if (line == N - 1)
		printf("%d\n", sum - result);
	else
		printf("-1\n");
	return 0;
}