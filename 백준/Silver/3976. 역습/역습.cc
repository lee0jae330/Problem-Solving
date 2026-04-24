#include<bits/stdc++.h>

using namespace std;

int dp[100001][2];

int pass[100002][2];
int dribble[100002][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		memset(dp, 0, sizeof(dp));

		int N, l1, l2, s1, s2;
		cin >> N >> l1 >> l2 >> s1 >> s2;

		for (int i = 1; i <= N - 1; i++) {
			cin >> pass[i][0];
		}

		for (int i = 1; i <= N - 1; i++) {
			cin >> dribble[i][0];
		}

		for (int i = 1; i <= N - 1; i++) {
			cin >> pass[i][1];
		}

		for (int i = 1; i <= N - 1; i++) {
			cin >> dribble[i][1];
		}

		dp[0][0] = l1;
		dp[0][1] = l2;

		for (int i = 1; i <= N - 1; i++) {
			dp[i][0] = min(dp[i - 1][0] + dribble[i][0], dp[i - 1][1] + pass[i][1]);
			dp[i][1] = min(dp[i - 1][1] + dribble[i][1], dp[i - 1][0] + pass[i][0]);
		}

		cout<< min(dp[N-1][0]+s1,dp[N-1][1]+s2) <<'\n';
	}
	return 0;
}