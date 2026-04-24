#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

unsigned long long int arr[101][101];
unsigned long long int sol[101][101];

int main(void)
{
	int N;
	scanf("%d", &N);
	sol[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%llu", &arr[i][j]);
			if (!arr[i][j])
				continue;
			if (sol[i][j] != 0) {
				if (i + arr[i][j] < N) {
					sol[i + arr[i][j]][j] += sol[i][j];
				}
				if (j + arr[i][j] < N) {
					sol[i][j + arr[i][j]] += sol[i][j];
				}
			}
		}
		getchar();
	}
	printf("%llu\n", sol[N - 1][N - 1]);
	return 0;
}