#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

vector<string> v;

int main(void) {
	fastio();
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		v.push_back(str.substr(i, str.length() - i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}