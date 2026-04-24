#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int arr[4000001];
int check[4000001];
int N, M, K;
vector<int>v;



int main(void)
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < K; i++)
	{
		if (!check[*upper_bound(v.begin(), v.end(), arr[i])])
		{
			printf("%d\n", *upper_bound(v.begin(), v.end(), arr[i]));
			check[*upper_bound(v.begin(), v.end(), arr[i])] = 1;
		}
		else
		{
			int idx = upper_bound(v.begin(), v.end(), arr[i])-v.begin();
			while (check[v[idx]])
			{
				idx++;
			}
			printf("%d\n", v[idx]);
			check[v[idx]] = 1;
		}

	}
	return 0;
}