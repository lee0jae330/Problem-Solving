//*s1 & #dp & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

vector<int> v[9];

int dp[100001][9];
int mod = 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	v[1].push_back(2);
	v[1].push_back(3);

	v[2].push_back(1);
	v[2].push_back(3);
	v[2].push_back(4);

	v[3].push_back(1);
	v[3].push_back(2);
	v[3].push_back(4);
	v[3].push_back(5);

	v[4].push_back(2);
	v[4].push_back(3);
	v[4].push_back(5);
	v[4].push_back(6);

	v[5].push_back(3);
	v[5].push_back(4);
	v[5].push_back(6);
	v[5].push_back(7);

	v[6].push_back(4);
	v[6].push_back(5);
	v[6].push_back(8);

	v[7].push_back(5);
	v[7].push_back(8);

	v[8].push_back(6);
	v[8].push_back(7);

	dp[0][1] = 1;

	for (int i = 1; i <= 100000; i++) {
		for (int j = 1; j <= 8; j++) {
			int sum = 0;
			for (int k = 0; k < v[j].size(); k++) {
				sum += dp[i - 1][v[j][k]];
				sum %= mod;
			}
			dp[i][j] = sum;
		}
	}

	int D;
	cin >> D;
	cout << (dp[D - 1][2] + dp[D - 1][3]) % mod << '\n';
	return 0;

}