#include<bits/stdc++.h>

using namespace std;

vector<int>v[10];

int dp[1001][10];
int mod = 1234567;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	v[0].push_back(7);
	
	v[1].push_back(2);
	v[1].push_back(4);

	v[3].push_back(2);
	v[3].push_back(6);

	v[9].push_back(6);
	v[9].push_back(8);

	v[2].push_back(1);
	v[2].push_back(3);
	v[2].push_back(5);

	v[4].push_back(1);
	v[4].push_back(5);
	v[4].push_back(7);

	v[6].push_back(3);
	v[6].push_back(5);
	v[6].push_back(9);

	v[7].push_back(0);
	v[7].push_back(4);
	v[7].push_back(8);

	v[8].push_back(5);
	v[8].push_back(7);
	v[8].push_back(9);

	v[5].push_back(2);
	v[5].push_back(4);
	v[5].push_back(6);
	v[5].push_back(8);
	
	for (int i = 0; i < 10; i++) {
		dp[2][i] = v[i].size();
	}

	for (int i = 3; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			long long sum =0;
			for (int k = 0; k < v[j].size(); k++) {
				sum+= (dp[i-1][v[j][k]]) % mod;
			}
			dp[i][j] = (sum%mod);
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N == 1) {
			cout << 10 <<'\n';
			continue;
		}
		long long sum =0;
		for (int i = 0; i < 10; i++) {
			sum += dp[N][i];
			sum %=mod;
		}
		cout << sum <<'\n';
	}
	return 0;
}