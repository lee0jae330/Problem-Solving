#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 9;
long long dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;
	for (int i = 7; i <= 100000; i++) {
		dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % mod;
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}
