#include<bits/stdc++.h>

using namespace std;

int T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> N;
		int tmp = N%100;
		if ((N + 1) % tmp) {
			cout << "Bye" <<'\n';
		}
		else {
			cout << "Good" <<'\n';
		}
	}
	return 0;
}