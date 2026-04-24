#include<bits/stdc++.h>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		fill(dp,dp+1001,-12345678);
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			dp[i] = arr[i];
		}

		int sol = dp[0];

		for (int i = 1; i < N; i++) {
			dp[i] = max(dp[i],arr[i]+dp[i-1]);
			sol = max(dp[i],sol);
		}

		cout << sol <<'\n';
	}
	return 0;
}