#include<bits/stdc++.h>

using namespace std;

int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[1]=1;
	dp[2]=1;
	dp[5]=1;
	dp[7]=1;


	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		if(i==1||i==2||i==5||i==7)
			continue;
		if (i - 1 > 0) {
			dp[i] = dp[i-1];
		}
		if (i - 2 > 0) {
			dp[i] = min(dp[i],dp[i-2]);
		}
		if (i - 5 > 0) {
			dp[i] = min(dp[i],dp[i-5]);
		}
		if (i - 7 > 0) {
			dp[i] = min(dp[i],dp[i-7]);
		}
		dp[i]++;
	}
	cout << dp[N]<<'\n';
	return 0;
}