#include<iostream>

using namespace std;

int main(void) {

	int N;	cin >> N;

	int cnt = 1, sol=0,b=0;

	int f = 0;

	while (1) {

		int tmp = N - cnt;

		if (tmp < cnt + 1) {

			if (f) {

				sol = cnt + 1 - tmp;

				b = 1;

			}

			else {

				b = 1;

			}

		}

		if (!f)

			f = 1;

		else

			f = 0;

		if (b)

			break;

		N -= cnt;

		cnt++;

	}

	cout << sol;

}

 