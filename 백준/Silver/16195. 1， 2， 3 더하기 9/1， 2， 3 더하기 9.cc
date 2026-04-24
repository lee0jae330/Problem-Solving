#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 9;
long long dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[1][1] = 1;

	dp[2][1] = 1;
	dp[2][2] = 1;

	dp[3][3] = 1;
	dp[3][2] = 2;
	dp[3][1] = 1;

	for (int i = 4; i <= 1000; i++) {
		for (int j = 2; j <= 1000; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % mod;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		long long sol = 0;
		for (int i = 0; i <= m; i++) {
			sol += dp[n][i];
			sol %= mod;
		}
		cout << sol << '\n';
	}
	return 0;

}