#include<bits/stdc++.h>

using namespace std;

int dp[1001];

vector<int>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int C,N;
	cin >> C >> N;
	while (N--) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());

	for (int num : v) {
		dp[num] = 1;
	}

	for (int i = 1; i <= C; i++) {
		auto iter = find(v.begin(),v.end(),i);
		if (iter != v.end()) {
			continue;
		}
		
		for (int num : v) {	
			if (i - num > 0) {
				if(!dp[i])
					dp[i] = dp[i-num] +1;
				else {
					dp[i] = min(dp[i], dp[i-num]+1);
				}
			}
		}
	}

	cout << dp[C] <<'\n';
	return 0;
}