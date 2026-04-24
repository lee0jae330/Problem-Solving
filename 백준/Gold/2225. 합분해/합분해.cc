#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9;

int N,K;

int dp[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	for (int i = 0; i <= 200; i++) {
		dp[i][1] = 1;
	}

	for (int i = 0; i <= 200; i++) {
		for (int j = 2; j <= 200; j++) {
			int sum =0;
			for (int k = 0; k <= i; k++) {
				sum += dp[i-k][j-1];
				sum%=mod;
			}
			dp[i][j]=sum;
		}
	}
	cout << dp[N][K] <<'\n';
	return 0;
}