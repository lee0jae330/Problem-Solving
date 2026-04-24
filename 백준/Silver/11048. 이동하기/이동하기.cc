#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[1001][1001];
int sol[1001][1001];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
		getchar();
	}
	sol[0][0] = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 1 < N) {
				if (!sol[i + 1][j]) {
					sol[i + 1][j] = sol[i][j]+arr[i + 1][j];
				}
				else {
					sol[i + 1][j] = max(sol[i + 1][j], sol[i][j] + arr[i + 1][j]);
				}
			}
			if (j + 1 <M) {
				if (!sol[i][j + 1]) {
					sol[i][j + 1] = sol[i][j] + arr[i][j + 1];
				}
				else {
					sol[i][j + 1] = max(sol[i][j + 1], sol[i][j]+arr[i][j + 1]);
				}
			}
			if (i + 1 < N && j + 1 < M) {
				if (!sol[i + 1][j + 1]) {
					sol[i + 1][j + 1] = sol[i][j] + arr[i + 1][j + 1];
				}
				else {
					sol[i + 1][j + 1] = max(sol[i + 1][j + 1], sol[i][j] + arr[i + 1][j + 1]);
				}
			}
		}
	}
	printf("%d\n", sol[N - 1][M - 1]);
	return 0;
}