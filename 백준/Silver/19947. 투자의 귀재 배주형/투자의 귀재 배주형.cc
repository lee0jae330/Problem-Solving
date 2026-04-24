#include<bits/stdc++.h>

using namespace std;

long long dp[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long H, Y;
	cin >> H >> Y;

	dp[0] = H;
	double r1 = 0.05, r2 = 0.2, r3 = 0.35;

	for (int i = 1; i <= Y; i++) {
		if (i - 1 >= 0) {
			dp[i] = dp[i - 1] + dp[i - 1] * r1;
		}
		if (i - 3 >= 0) {
			long long tmp = dp[i - 3] + dp[i - 3] * r2;
			dp[i] = max(dp[i], tmp);
		}
		if (i - 5 >= 0) {
			long long tmp = dp[i - 5] + dp[i - 5] * r3;
			dp[i] = max(dp[i], tmp);
		}
	}
	cout << dp[Y] <<'\n';
	return 0;
}