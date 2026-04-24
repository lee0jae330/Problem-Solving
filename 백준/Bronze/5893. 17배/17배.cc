#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


string add(string s1, string s2) {
	string result = "";
	if (s1.size() < s2.size()) {
		swap(s1, s2);
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int carry = 0;

	for (int i = 0; i < s2.size(); i++) {
		int n1 = s1[i] - '0', n2 = s2[i] - '0';
		int num = n1 + n2 + carry;
		if (num > 1) {
			carry = 1;
			num %= 2;
		}
		else
			carry = 0;
		result.push_back(num + '0');
	}
	for (int i = s2.size(); i < s1.size(); i++) {
		int n = s1[i] - '0';
		int num = n + carry;
		if (num > 1) {
			carry = 1;
			num %= 2;
		}
		else
			carry = 0;
		result.push_back(num + '0');
	}
	if (carry)
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}

int main(void) {
	fastio();
	string s;
	cin >> s;
	string tmp = s;
	for (int i = 0; i < 4; i++) {
		s.push_back('0');
	}
	cout << add(s, tmp)<<"\n";
	return 0;
}