#include<iostream>

using namespace std;

void fastio() {

	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	cout.tie(NULL);

}

int arr[101][101];

int main(void) {

	fastio();

	int N, x, y;

	cin >> N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			cin >> arr[i][j];

			if (arr[i][j] == 2) {

				x = i, y = j;

			}

		}

	}

	int col=0, row=0;

	if (x % 2)

		col = 1;

	if (y % 2)

		row = 1;

	int sol = 0;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (arr[i][j] == 1) {

				if (col==row) {

					if (i % 2 && j % 2)

						sol = 1;

					else if (!(i % 2) && !(j % 2))

						sol = 1;

				}

				else {

					if (i % 2 && !(j % 2))

						sol = 1;

					else if (!(i % 2) && j % 2)

						sol = 1;

				}

			}

		}

	}

	if (sol)

		cout << "Kiriya";

	else

		cout << "Lena";

}