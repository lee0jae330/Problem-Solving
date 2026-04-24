#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		for (char c : str) {
			if (isupper(c)) {
				cout << (char)tolower(c);
			}
			else {
				cout << c;
			}
		}
		cout << '\n';
	}
	return 0;
}