#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int> Fail(string pattern) {
	int m = pattern.length();
	vector<int> pi(m);
	pi[0] = 0;
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> KMP(string pattern, string text) {
	int m = pattern.length();
	int n = text.length();
	vector<int> pos; // 검색 위치 
	vector<int>pi = Fail(pattern);

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]) {
			if (j == m - 1) {
				pos.push_back(i - m + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return pos;
}

int main(void) {
	fastio();
	string text, pattern;
	cin >> text >> pattern;
	
	vector<int> sol = KMP(pattern, text);
	if (sol.size() > 0)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}