#include<bits/stdc++.h>

using namespace std;

long long dp[100001][4];
long long mod = 1e9 + 9;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[1][1] = 1;

	dp[2][2] = 1;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
	}

	int T;
	cin >> T ;
	while (T--) {
		int N;
		cin >> N;
		cout << (dp[N][1]+dp[N][2]+dp[N][3]) % mod <<'\n';
	}
	return 0;
}