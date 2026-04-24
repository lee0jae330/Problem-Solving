#include<iostream>
#include<utility>
#include<algorithm>
#include<limits.h>

using namespace std;

int dp[101][10001];
pair<int, int>arr[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int total = 0;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first;
	}

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].second;
		total += arr[i].second;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= total; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - arr[i].second >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i].second] + arr[i].first);
			}
		}
	}

	int sol = INT_MAX;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= total; j++) {
			if (dp[i][j] >= M) {
				sol = min(sol, j);
			}
		}
	}

	cout << sol << '\n';
	return 0;
}
