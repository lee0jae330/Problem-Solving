#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1,s2;
	cin >> s1 >> s2;

	int N = s1.size();
	int M = s2.size();

	int sol = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			sol = max(sol,dp[i][j]);
		}
	}
	cout << sol <<'\n';
	return 0;
}