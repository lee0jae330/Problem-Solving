#include<bits/stdc++.h>

using namespace std;

int dp[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int A , K;
	cin >> A >> K;
	
	dp[A] = 0;
	for (int i = A + 1; i <= K; i++) {
		dp[i] = 1 + dp[i-1];
		if (i % 2 == 0 && (i/2) >=A) {
			dp[i] = min(dp[i],1+dp[i/2]);
		}
	}
	cout << dp[K] << '\n';
	return 0;
}