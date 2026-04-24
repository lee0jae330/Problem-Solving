#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	long long N;
	cin >> N;
	if (N == 1)
		cout << 0 << '\n';
	else
		cout << (N + 1) / 2 << '\n';
	return 0;
}