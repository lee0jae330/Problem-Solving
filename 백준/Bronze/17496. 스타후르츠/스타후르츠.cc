#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	int N, T, C, P;
	cin >> N >> T >> C >> P;
	int price = (N - 1) / T * C * P;
	cout << price << "\n";
	return 0;
}