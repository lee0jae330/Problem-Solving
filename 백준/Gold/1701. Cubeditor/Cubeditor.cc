#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool comp(int p1, int p2) {
	return p1 > p2;
}

int mx = 0;

void Fail(string pattern) {
	int m = pattern.length();

	vector<int>pi(m);
	pi[0] = 0;

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
			mx = max(mx, j);
		}
	}

	//return pi;
}

/*vector<int>KMP(string text, string pattern) {
	int n = text.length();
	int m = pattern.length();

	vector<int>pi = Fail(pattern);
	vector<int>pos;

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]) {
			if (j == m - 1) {
				pos.push_back(i-m+1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return pos;
}*/



int main(void) {
	fastio();
	string text;
	cin >> text;
	int len = text.length();
	for (int i = 0; i < len; i++) {
		string str = text.substr(i, len - i);
		Fail(str);
	}
	cout << mx << '\n';
	return 0;
}