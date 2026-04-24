#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	long long int N, R;
	cin >> N >> R;
	cout << 2 * R + N - 1 << "\n";
	return 0;
}