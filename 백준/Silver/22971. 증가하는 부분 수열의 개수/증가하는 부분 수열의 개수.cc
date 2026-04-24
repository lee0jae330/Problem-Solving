#include<bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

int arr[5001];
long long dp[5001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >>N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i]=1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i]+=dp[j];
				dp[i]%=mod;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << dp[i]<<' ';
	}
	return 0;
}