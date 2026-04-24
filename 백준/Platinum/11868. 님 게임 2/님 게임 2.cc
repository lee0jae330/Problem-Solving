#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>

using namespace std;
vector<int>v;

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	int tmp = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		tmp = tmp ^ v[i];
	}
	if (tmp == 0)
		printf("cubelover\n");
	else
		printf("koosaga\n");
	return 0;
}