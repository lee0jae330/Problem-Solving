#include<bits/stdc++.h>

using namespace std;

int N;
int arr[5001];
long long dp[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	fill(dp,dp+5001,LLONG_MAX);

	dp[1] = 0;
	dp[2] = 1+abs(arr[1]-arr[2]);

	for (long long i = 3; i <= N; i++) {
		long long tmp = LLONG_MAX;
		for (long long j = 1; j < i; j++) {
			long long k = (i-j) * (1+abs(arr[i]-arr[j]));
			k = max(dp[j],k);
			tmp = min (tmp, k);
		}
		dp[i] = tmp;
	}
	cout << dp[N] <<'\n';
	return 0;
}