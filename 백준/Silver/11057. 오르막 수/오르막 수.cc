#include<bits/stdc++.h>

using namespace std;

int dp[1001][11];
int mod = 1e4+7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] =1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k >= 0; k--) {
				dp[i][j] += dp[i-1][k];
				dp[i][j]%=mod;
			}
		}
	}

	int sol =0;
	for (int i = 0; i <= 9; i++) {
		sol += dp[N][i];
		sol%=mod;
	}

	cout << sol <<'\n';
	return 0;
}