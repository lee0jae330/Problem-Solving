#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

int arr[10001];
vector<int> v;

int main(void) {
	arr[0] = 1, arr[1] = 1;

	for (int i = 2; i < 10001 / i; i++) {
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < 10001; j += i) {
			if (j % i == 0)
				arr[j] = 1;
		}
	}
	for (int i = 2; i < 10001; i++) {
		if (arr[i] == 0)
			v.push_back(i);
	}

	int N;
	scanf("%d", &N);
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] * v[i + 1] > N) {
			printf("%d\n", v[i]*v[i + 1]);
			break;
		}
	}
	return 0;
}
