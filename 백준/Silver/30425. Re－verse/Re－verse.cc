#include<bits/stdc++.h>

using namespace std;

int N;
string str;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> str;
	int cnt = 1;
	int sz = str.size();
	for (int i = 1; i < sz; i++) {
		int idx = 0;
		int f = 0;
		for (int j = i; j < str.size(); j++) {
			if (str[idx] != str[j]) {
				f = 1;
				break;
			}
			idx++;
		}
		
		if (!f) {
			cnt++;
			str += str.substr(idx, str.size() - idx);
		}
	}
	cout << cnt << '\n';
	return 0;
}