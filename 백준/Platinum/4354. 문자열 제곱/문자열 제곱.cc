#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>Fail(string pattern) {
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

vector<int> KMP(string text, string pattern) {
	int n = text.length(), m = pattern.length();

	vector<int>pos;
	vector<int>pi = Fail(pattern);

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]) {
			if (j == m - 1) {
				pos.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return pos;
}

int main(void) {
	fastio();
	while (1) {
		string str;
		cin >> str;
		if (!str.compare("."))
			break;
		int len = str.length();
		vector<int>v = Fail(str);
		if(len%(len-v[len-1])==0)
			cout << len/(len-v[len - 1]) << '\n';
		else
			cout << 1 << '\n';
	}
	return 0;
}