#include<iostream>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N,S,E;
		cin >> N >> S >> E;
		if (S == 1) {
			if (E == N) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 <<'\n';
			}
		}
		else if (S == N) {
			if (E == 1) {
				cout << 0 <<'\n';
			} else {
				cout << 1 <<'\n';
			}

		} else if (abs(S-E)==1 ){
			cout << 1 <<'\n';
		}
		else {
			cout << 2 <<'\n';
		}

	}
	return 0;
}