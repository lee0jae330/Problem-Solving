#include<iostream>

using namespace std;

int main(void) {

	int x, y;	cin >> x >> y;

	int a = 100 - x, b = 100 - y;

	int c = 100 - (a + b);

	int d = a * b;

	int q = 0, r = d % 100;

	if (d > 99) {

		q = d / 100;

	}

	cout << a << ' ' << b << ' ' << c << ' ' << d<<' ' << q << ' ' << r << '\n';

	cout << c + q << ' ' << r;

}

 