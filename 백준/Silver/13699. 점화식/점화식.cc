#include<bits/stdc++.h>

using namespace std;

long long dp[36];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;

	dp[0]=1;
	
	for (int i = 1; i <= N; i++) {
		long long sum = 0;
		if (i % 2) {
			for (int j = 0; j < (i - 1) / 2; j++) {
				sum+= dp[j] * dp[i-1-j];
			}
			dp[i]=sum*2;
			dp[i] += dp[i/2]*dp[i/2];
		}
		else {
			
			for (int j = 0; j < i / 2; j++) {
				sum += dp[j]*dp[i-1-j];
			}
			dp[i] = sum*2;
		}
	}
	
	cout << dp[N] <<'\n';
	return 0;
}