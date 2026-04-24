#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int arr[100001];

void init() {
	for (int i = 0; i < 100001; i++) {
		arr[i] = i;
	}
}

int main(void) {
	init();
	for (int i = 2; i < 100001; i++) {
		int tmp = sqrt(i);
		for (int j = 1; j <= tmp; j++) {
			arr[i] = min(arr[i], arr[i - j*j] + 1);
		}
	}
	int N;
	scanf("%d", &N);
	printf("%d\n", arr[N]);
	return 0;
}