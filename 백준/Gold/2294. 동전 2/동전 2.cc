#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

int arr[100001];
vector<int> v;

int main(void) {
	memset(arr, -1, sizeof(arr));
	arr[0]=0;
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int coin;
		scanf("%d", &coin);
		arr[coin] = 1;
		v.push_back(coin);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i < v[j])
				break;
			if (arr[i - v[j]] == -1)
				continue;
			if (arr[i] == -1)
					arr[i] = arr[i - v[j]] + 1;
			else {
					arr[i] = min(arr[i], arr[i - v[j]] + 1);
			}
		}
	}
	if (arr[K] == -1)
		printf("-1\n");
	else
		printf("%d\n", arr[K]);
	return 0;
}