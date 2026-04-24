#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

queue<int>q;
int arr[1025];

int pow(int n)
{
	int tmp = 1;
	for (int i = 0; i < n; i++)
		tmp *= 2;
	return tmp;
}

int main(void)
{
	int K;
	scanf("%d", &K);
	for (int i = 1; i <= pow(K) - 1; i++)
		scanf("%d", &arr[i]);
	int lev = 0;
	int minus = pow(K-1)/2;
	q.push((pow(K-1)));
	while (lev < K)
	{
		for (int i = 0; i < pow(lev); i++)
		{
			int tmp = q.front();
			q.pop();
			printf("%d ", arr[tmp]);
			q.push(tmp - minus);
			q.push(tmp + minus);
		}
		minus/=2;
		lev++;
		printf("\n");
	}
	return 0;
}