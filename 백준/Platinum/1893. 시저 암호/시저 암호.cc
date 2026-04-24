#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>Fail(string pattern) {
	int m = pattern.length();
	
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

vector<int>KMP(string text, string pattern) {
	int n = text.length(), m = pattern.length();

	vector<int>pi = Fail(pattern);
	vector<int>pos;

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]){
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

vector<int>sol;
map<char, int>m;

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T > 0) {
		T--;
		sol.clear();
		m.clear();
		string A, W, S;
		cin >> A >> W >> S;
		int len = A.length();
		for (int i = 0; i < len; i++)
			m[A[i]]=i;

		int s_len = S.length();
		int w_len = W.length();
		for (int i = 0; i < len; i++) {
			string tmp = W;
			for (int j = 0; j < w_len; j++) {
				tmp[j] = A[(m[tmp[j]] + i) % len];
			}
			vector<int>v = KMP(S, tmp);
			if (v.size() == 1) {
				sol.push_back(i);
			}
		}
		if (sol.size() == 1)
			cout << "unique: " << sol[0] << '\n';
		else if (sol.size() > 1) {
			cout << "ambiguous: ";
			for (int i = 0; i < sol.size(); i++)
				cout << sol[i] << ' ';
			cout << '\n';
		}
		else
			cout << "no solution" << '\n';
	}
	return 0;
}