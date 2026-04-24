#include<iostream>
#include<string>
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

int main(void) {
	fastio();
	int N;
	cin >> N;
	string text;
	cin >> text;
	vector<int> v = Fail(text);
	cout << N - v[N - 1]<<'\n';
	return 0;

}