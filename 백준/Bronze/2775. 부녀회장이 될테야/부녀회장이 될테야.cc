#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int arr[15][15];

int main(void) {
	fastio();
	for (int i = 0; i < 15; i++) {
		arr[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			int sum = 0;
			for (int k = 1; k <= j; k++) {
				sum += arr[i - 1][k];
			}
			arr[i][j] = sum;
		}
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int K, N;
		cin >> K >> N;
		cout << arr[K][N] << '\n';
	}
	return 0;
}