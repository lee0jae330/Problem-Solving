#include<bits/stdc++.h>

using namespace std;

double arr[10001];
double dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i],dp[i-1]*arr[i]);
	}

	double sol = -1;

	for (int i = 1; i <= N; i++) {
		sol = max(sol,dp[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << sol <<'\n';
	return 0;
}