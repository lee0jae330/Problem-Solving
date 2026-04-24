#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[1001][1001];

int main(void) {
	fastio();
	int num = 1;
	for (int i = 2; i < 1001; i++) {
		for (int j = i-1; j > 0; j--) {
			arr[j][i - j] = num++;
		}
	}

	int N;
	cin >> N;
	for (int i = 1; i < 1001; i++) {
		for (int j = 1; j < 1001; j++) {
			if (arr[i][j] == N) {
				cout << i << ' ' << j << '\n';
				return 0;
			}
		}
	}
	return 0;
}