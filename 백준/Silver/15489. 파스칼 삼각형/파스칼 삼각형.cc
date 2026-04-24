#include<bits/stdc++.h>

using namespace std;

long long dp[31][31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) {
				dp[i][j]=1;
			}
			else {
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}
		}
	}
	
	int R,C,W;
	cin >> R >> C >> W;

	long long sol = 0;

	for (int i = 0; i < W; i++) {
		for (int j = 0; j <= i; j++) {
			sol += dp[R+i][C+j];
		}
	}
	
	cout << sol <<'\n';
	return 0;
}