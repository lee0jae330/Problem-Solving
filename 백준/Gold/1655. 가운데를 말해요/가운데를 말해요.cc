#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int>maxh;
priority_queue<int, vector<int>, greater<int>>minh;

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		if (i == 0)
		{
			maxh.push(num);
			printf("%d\n", maxh.top());
			continue;
		}
		if (i % 2 == 0)
			maxh.push(num);
		else
			minh.push(num);
		if (maxh.top() > minh.top())
		{
			int x = maxh.top();
			int y = minh.top();
			maxh.pop(), minh.pop();
			maxh.push(y);
			minh.push(x);
		}
		printf("%d\n", maxh.top());
	}
	return 0;
}