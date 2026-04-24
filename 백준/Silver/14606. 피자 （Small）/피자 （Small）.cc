#include<bits/stdc++.h>

using namespace std;

int dp[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	dp[1]=0;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i-1]+ i-1;
	}

	cout << dp[N] <<'\n';
	return 0;
}