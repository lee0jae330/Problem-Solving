#include<bits/stdc++.h>

using namespace std;

int arr[1025][1025];
long long dp[1025][1025];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = arr[i][j] + dp[i][j - 1];
		}
	}

	int K;
	cin >> K;
	while (K--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		long long sol = 0;
		for (int i = x1; i <= x2; i++) {
			sol += (dp[i][y2]-dp[i][y1-1]);
		}
		cout << sol <<'\n';
	}
	return 0;

}
