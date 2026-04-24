//*s1 & #dp & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

string str;

int dp[3001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> str;

	if (str[0] >= 'a' && str[0] <= 'z') {
		dp[0][0] = 1;
		dp[0][1] = 3;
	}
	else {
		dp[0][0] = 2;
		dp[0][1] = 2;
	}

	for (int i = 1; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][0] + 3, dp[i - 1][1] + 2);
		}
		else {
			dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 3);
			dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
		}
	}

	cout << min(dp[str.size() - 1][0], dp[str.size() - 1][1]);
	return 0;
}