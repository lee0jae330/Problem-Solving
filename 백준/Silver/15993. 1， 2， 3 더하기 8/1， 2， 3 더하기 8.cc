#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 9;
long long dp[100001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[1][0] = 0;
	dp[1][1] = 1;

	dp[2][0] = 1;
	dp[2][1] = 1;

	dp[3][0] = 2;
	dp[3][1] = 2;

	for (int i = 4; i <= 100000; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % mod;
	}

	int T;
	cin >>T;
	while (T--) {
		int N;
		cin >> N;
		cout << dp[N][1] <<' ' << dp[N][0] <<'\n';
	}
	return 0;
}