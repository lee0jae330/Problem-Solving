#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	int sum = 0, tmp=0;
	while (1) {
		sum += tmp;
		if (N <= 6 * sum + 1) {
			cout << tmp + 1 << '\n';
			break;
		}
		tmp++;
	}
	return 0;
}