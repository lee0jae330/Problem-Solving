#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> v;

bool comp(string s1, string s2) {
	string a = s1 + s2;
	string b = s2 + s1;
	return a > b;
}


bool comp1(string s1, string s2) {
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	return s1.length() < s2.length();
}

int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '6')
				s[j] = '9';
			else if (s[j] == '9')
				s[j] = '6';
		}
		reverse(s.begin(), s.end());
		v.push_back(s);
	}
	
	sort(v.begin(), v.end(),comp1);

	v.push_back(v[N - 1]);
	sort(v.begin(), v.end(), comp);
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		reverse(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].length(); j++) {
			if (v[i][j] == '6') {
				v[i][j] = '9';
			}
			else if (v[i][j] == '9')
				v[i][j] = '6';
			cout << v[i][j];
		}
	}
	cout << '\n';
	return 0;
}