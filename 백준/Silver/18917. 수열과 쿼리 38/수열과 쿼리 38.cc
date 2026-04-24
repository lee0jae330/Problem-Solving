#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}



int main(void) {
	fastio();
	int M;
	cin >> M;
	long long sum = 0,XOR=0;
	
	for (int i = 0; i < M; i++) {
		int num;
		long long n;
		cin >> num;
		if (num == 1) {
			cin >> n;
			sum += n;
			XOR ^= n;
		}
		else if (num == 2) {
			cin >> n;
			sum -= n;
			XOR ^= n;
		}
		else if (num == 3) {
			cout << sum << '\n';
		}
		else {
			cout << XOR << '\n';
		}
	}
	return 0;
}