#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

string s1, s2;
string result;

void rec(int x, int y) {
	if(!dp[x][y])
		return;
	if (dp[x - 1][y] == dp[x][y]) {
		rec(x-1,y);
	}
	else if (dp[x][y - 1] == dp[x][y]) {
		rec(x,y-1);
	}
	else {
		result.push_back(s1[x - 1]);
		rec(x - 1, y - 1);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> s1 >> s2;

	int N = s1.size();
	int M = s2.size();

	int sol = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			sol = max(sol,dp[i][j]);
		}
	}
	cout << sol <<'\n';
	rec(N,M);
	for(int i=result.size()-1;i>=0;i--)
		cout << result[i];
	return 0;
}