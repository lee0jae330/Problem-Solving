#include<bits/stdc++.h>

using namespace std;

int arr[502][502];
int dp[502][502];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i-1][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);
			}
			dp[i][j]+=arr[i][j];
		}
	}

	int sol = -1;
	for (int i = 1; i <= N; i++) {
		sol = max(sol,dp[N][i]);
	}
	cout << sol <<'\n';
	return 0;
}