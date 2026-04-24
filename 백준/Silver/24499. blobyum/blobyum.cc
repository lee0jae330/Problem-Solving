#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int arr[100001];

int main(void) {
	fastio();
	int N, K;
	cin >> N >> K;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < K; i++) {
		sum += arr[i];
	}
	int result = sum;
	int tmp = sum;
	for (int i = K; i < N+K-1; i++) {
		tmp -= arr[i - K];
		tmp += arr[i%N];
		result = max(result, tmp);
	}
	cout << result << '\n';
	return 0;
}