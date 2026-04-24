#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	string s1;
	cin >> s1;
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	if (s1 == s2)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}