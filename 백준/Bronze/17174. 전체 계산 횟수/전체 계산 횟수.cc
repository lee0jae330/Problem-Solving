#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	int result = N;
	while (N) {
		result += N / M;
		N /= M;
	}
	cout << result << '\n';
	return 0;
}