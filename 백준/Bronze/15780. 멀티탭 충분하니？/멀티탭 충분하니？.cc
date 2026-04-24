#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N,K;
	cin >> N >> K;

	int available = 0;

	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		available += (num / 2) + (num % 2);
	}

	if (available >= N) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" <<'\n';
	}

	return 0;
}