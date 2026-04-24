#include<bits/stdc++.h>

using namespace std;

long long dp[1001][1001];
long long mod = 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	dp[1][1] = 1;

	for (int i = 1; i <= N; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= M; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= M; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
		}
	}

	cout << dp[N][M] << '\n';
	return 0;
}