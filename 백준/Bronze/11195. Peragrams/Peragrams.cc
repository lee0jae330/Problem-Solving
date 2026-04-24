#include<iostream>
#include<string>
#include<set>

using namespace std;

int arr[26];
set<int>s;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int idx = str[i] - 'a';
		arr[idx]++;
		s.insert(idx);
	}

	if (s.size() == 1) {
		cout << 0 << '\n';
		return 0;
	}

	int odd = 0; 
	for (auto i : arr) {
		if(i == 0) 
			continue;
		if(i%2)
			odd++;
	}
	if(odd)
		cout << odd -1 <<'\n';
	else
		cout << 0 <<'\n';

	return 0;
}