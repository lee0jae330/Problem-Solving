#include<bits/stdc++.h>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	int sol = dp[1];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j]+arr[i]);
			}
		}
		sol = max(sol,dp[i]);
	}

	cout << sol <<'\n';

	return 0;
}