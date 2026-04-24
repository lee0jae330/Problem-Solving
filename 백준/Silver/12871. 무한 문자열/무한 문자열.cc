#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int gcd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void) {
	fastio();
	string s1, s2;
	cin >> s1 >> s2;
	int g;
	if (s1.size() >= s2.size()) {
		g = gcd(s1.size(), s2.size());
	}
	else {
		g = gcd(s2.size(), s1.size());
	}
	int len = g * (s1.size() / g) * (s2.size() / g);
	int n1 = len / s1.size(), n2 = len / s2.size();
	string tmp1="", tmp2="";
	for (int i = 0; i < n1; i++)
		tmp1 += s1;
	for (int i = 0; i < n2; i++)
		tmp2 += s2;
	if (tmp1 == tmp2)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
	return 0;
}