#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	bool oddodd = false, oddeven = false, evenodd = false, eveneven = false;

	for (int i = 0; i < K; i++) {
		int x,y;
		cin >> x >> y;
		if (x % 2 && y % 2) {
			oddodd=true;
		}
		else if (x % 2) {
			oddeven = true;
		}
		else if (y % 2) {
			evenodd = true;
		}
		else {
			eveneven = true;
		}
	}
	if (oddodd && oddeven && evenodd && eveneven) {
		cout << "YES" <<'\n';
	}
	else {
		cout << "NO" <<'\n';
	}
	return 0;
}