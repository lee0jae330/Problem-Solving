#include<bits/stdc++.h>

using namespace std;

int arr[10001];
int dp[10001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i][1]= arr[i];
	}

	int sol = -1;

	for (int i = 1; i <= N; i++) {
		for (int j = i - 2; j >= 0; j--) {
			dp[i][1] = max(dp[i][1],arr[i]+dp[j][1]);
			dp[i][1] = max(dp[i][1],arr[i]+dp[j][2]);
		}

		if (i - 1 >= 1) {
			dp[i][2] = max(dp[i][2], arr[i]+dp[i-1][1]);
		}
		sol = max(sol, max(dp[i][1],dp[i][2]));
	}
	/*
	for (int i = 1; i <= N; i++) {
		cout << dp[i][1] <<' '<<dp[i][2] <<'\n';
	}
	*/
	cout << sol <<'\n';
	return 0;
}