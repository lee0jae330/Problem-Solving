#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>card;
int arr[100002];
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		if (arr[num] == 0)
			card.push_back(num);
		arr[num]++;
	}


	for (int i = 0; i < card.size(); i++)
	{
		if (arr[card[i]] % 2 == 1)
		{
			printf("koosaga");
			return 0;
		}
	}
	printf("cubelover");

	return 0;
}