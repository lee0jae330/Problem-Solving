#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int> Fail(vector<int>pattern) {
	int m = pattern.size();

	vector<int>pi(m);
	pi[0] = 0;
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}
	return pi;
}

bool KMP(vector<int>text, vector<int> pattern) {
	int n = text.size(), m=pattern.size();
	vector<int>pi = Fail(pattern);
	
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]) {
			if (j == m - 1)
				return true;
			else
				j++;
		}
	}
	return false;
}


vector<int>v[101];
int main(void) {
	fastio();
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int n;
			cin >> n;
			v[i].push_back(n);
		}
	}

	for (int i = 0; i < v[0].size() -K+ 1; i++) {
		vector<int> virus_code(K);
		for (int j = 0; j < K; j++)
			virus_code[j] = v[0][i + j];
		vector<int>revers = virus_code;
		int flag = 0;
		reverse(revers.begin(), revers.end());
		for (int j = 1; j < N; j++) {
			if (!KMP(v[j], virus_code) && !KMP(v[j], revers)) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
	return 0;
}