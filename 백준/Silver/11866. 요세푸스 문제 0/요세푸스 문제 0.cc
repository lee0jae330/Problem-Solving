#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

int main(void)
{
	queue<int>q;
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		q.push(i + 1);
	int count = 0;
	int i = 1;
	printf("<");
	while (1)
	{
		if (i % K != 0)
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		else
		{
			printf("%d", q.front());
			if(count<N-1)
				printf(", ");
			q.pop();
			count++;
		}
		i++;
		if (count == N)
			break;
	}
	printf(">");
	return 0;
}