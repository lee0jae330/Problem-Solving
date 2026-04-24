#include<iostream>

using namespace std;

int main() {
	int T, S;
	cin >> T >> S;
	if (!S && T >= 12 && T <= 16) {
		cout << 320;
	}
	else
		cout << 280;
	return 0;
}