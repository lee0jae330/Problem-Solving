#include<bits/stdc++.h>

using namespace std;

int dp[5002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	fill(dp,dp+5002,-1);

	dp[3]=1;
	dp[5]=1;

	for (int i = 6; i <= N; i++) {
		if (dp[i - 3] != -1 && dp[i - 5] != -1) {
			dp[i] = min(dp[i-3],dp[i-5])+1;
		}
		else if (dp[i - 3] != -1) {
			dp[i] = dp[i-3]+1;
		}
		else if (dp[i - 5] != -1) {
			dp[i] = dp[i-5]+1;
		}
	}

	cout << dp[N] <<'\n';
	return 0;
}