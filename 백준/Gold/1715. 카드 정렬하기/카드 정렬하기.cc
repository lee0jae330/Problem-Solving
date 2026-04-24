#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
using namespace std;

priority_queue<int>pq;
int result = 0;

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		pq.push(-num);
	}
	if (pq.size() == 1)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		int tmp = 0;
		int sum=0;
		while (1)
		{
			tmp++;
			int t = -pq.top();
			pq.pop();
			sum += t;
			if (tmp % 2 == 0)
			{
				pq.push(-sum);
				result += sum;
				sum = 0;
			}
			if (pq.size() == 1)
			{
				sum += -pq.top();
				result += sum;
				printf("%d\n", result);
				return 0;
			}
		}
	}
}