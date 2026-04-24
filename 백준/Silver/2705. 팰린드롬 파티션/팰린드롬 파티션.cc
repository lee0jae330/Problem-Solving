#include<bits/stdc++.h>

using namespace std;

long long dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0] = 1;
	dp[1] = 1;

	dp[2] = 2;
	dp[3] = 2;

	for (int i = 4; i <= 1000; i++) {
		dp[i] = 1;
		if (i % 2 == 0)
			dp[i] += dp[i / 2];
		for (int j = 1; j < i ; j++) {
			if ((i - j) % 2)
				continue;
			dp[i] += dp[(i - j) / 2];
		}
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