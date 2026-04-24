#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int start = 1, end = 1;
	int sum = 0;
	int count = 1;
	while (end <= N)
	{
		if (sum >= N){
            if(sum==N)
              count++;
			sum -= start++;
        }
		else if (sum < N)
			sum += end++;
	}
	printf("%d\n", count);
	return 0;
}