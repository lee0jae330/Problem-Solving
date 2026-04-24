#include<bits/stdc++.h>

using namespace std;

int arr[8][8];
int dp[8][8][3];

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
			if (j == 1) {
				dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + arr[i][j];
				dp[i][j][1] = dp[i-1][j][0] + arr[i][j];
			}
			else if (j == M) {
				dp[i][j][1] = dp[i - 1][j][2] + arr[i][j];
				dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + arr[i][j];
			}
			else {
				dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + arr[i][j];
				dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];
				dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + arr[i][j];
			}
			
		}
	}

	int sol = 123456789;

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 3; j++) {
			if(i==1&&j==2)
				continue;
			if(i==M&&j==0)
				continue;
			sol = min(dp[N][i][j], sol);
		}
		
	}
	cout << sol <<'\n';
	return 0;
}