#include<bits/stdc++.h>

using namespace std;

int hp[21];
int enjoy[21];

int dp[21][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> hp[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> enjoy[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 99; j++) {
			dp[i][j] = dp[i-1][j];
			if (j - hp[i] >= 0) {
				dp[i][j] = max(dp[i][j],dp[i-1][j-hp[i]]+enjoy[i]);
			}
		}
	}

	cout << dp[N][99] <<'\n';
	return 0;
}