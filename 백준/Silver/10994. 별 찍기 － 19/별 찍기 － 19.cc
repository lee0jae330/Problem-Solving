#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[400][400];

void rec(int N, int x, int y) {
	if (N == 1) {
		arr[x][y] = '*';
		return;
	}
	else {
		char c;
		if (N % 2 == 0) {
			c = ' ';
		}
		else {
			c = '*';
		}
		for (int i = y; i < y + 2*N-1; i++)
			arr[x][i] = c;
		for (int i = x + 1; i < x + 2*N-2; i++) {
			arr[i][y] = c; arr[i][y +2*N - 2] = c;
		}
		for (int i = y; i < y + 2*N-1 ; i++) {
			arr[x + 2*N-2 ][i] = c;
		}
		rec(N - 1, x + 1, y + 1);
		return;
	}
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	int num = 2 * N - 1;
	rec(num, 0, 0);
	for (int i = 0; i <2*num-1; i++) {
		for (int j = 0; j < 2*num-1; j++)
			cout << arr[i][j];
		cout << '\n';
	}
	return 0;
}