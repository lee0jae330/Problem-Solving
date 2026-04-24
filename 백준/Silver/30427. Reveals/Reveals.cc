#include<bits/stdc++.h>

using namespace std;

string msg;
int N, M;

vector<string> v;
set<string>s;

int arr[1001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	getline(cin, msg);
	cin >> N;
	int flag = 0;
	string suspect;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "dongho") {
			suspect = "dongho";
			flag = 1;
		}
		v.push_back(str);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	if (flag) {
		cout << suspect << '\n';
		return 0;
	}
	vector<string>tmp;
	for (int i = 0; i < N; i++) {
		if (s.find(v[i]) == s.end()) {
			tmp.push_back(v[i]);
		}
	}

	if (tmp.size() == 1) {
		cout << tmp[0] << '\n';
		return 0;
	}
	
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == "bumin") {
			cout << "bumin" << '\n';
			return 0;
		}
	}

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == "cake") {
			cout << "cake" << '\n';
			return 0;
		}
	}

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == "lawyer") {
			cout << "lawyer" << '\n';
			return 0;
		}
	}

	if (tmp.size() >= 1) {
		sort(tmp.begin(), tmp.end());
		cout << tmp[0] << '\n';

	}
	else
		cout << "swi" << '\n';
	
	return 0;
}