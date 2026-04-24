#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	fastio();
	int N, L, D;
	cin >> N >> L >> D;

	int x = 1;

	for (int i = 1; i <= N; i++) {
		int a = L * i+5*(i-1), b = L * i + 5 * i; //b는 노래 시작 타이밍
		while (1) {
			int start = x * D, end = x * D + 1;
			if ((start >= a && start < b)) {
				cout << start << '\n';
				return 0;
			}
			else if (start < a) {
				x++;
				continue;
			}
			else {
				break;
			}
			if (end > a && end <= b) {
				cout << end << '\n';
				return 0;
			}
			else if (end < a) {
				x++;
				continue;
			}
			else {
				break;
			}
		}
	}
	if (x * D >= N * L + 5 * (N - 1)) {
		cout << x * D << '\n';
		return 0;
	}
	if (x * D + 1 >= N * L + 5 * (N - 1)) {
		cout << x * D + 1 << '\n';
		return 0;
	}
	cout << (x + 1) * D << '\n';
	return 0;
}