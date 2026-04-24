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


int main(void) {
	fastio();
	string text;
	cin >> text;
	vector<int> v = Fail(text);
	vector<pair<int, int>>sol;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0) {
			int len = i + 1;
			if (len % (len - v[i]))
				continue;
			sol.push_back({ len, len / (len - v[i]) });
		}
	}
	sort(sol.begin(), sol.end());
	for (int i = 0; i < sol.size(); i++)
		cout << sol[i].first << ' ' << sol[i].second << '\n';
	return 0;
}