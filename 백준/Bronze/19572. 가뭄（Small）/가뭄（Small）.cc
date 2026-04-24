#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	double d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	double a = (d1 + d2 - d3) / 2.;
	double b = (d1 - d2 + d3) / 2.;
	double c = (-d1 + d2 + d3) / 2.;
	cout << fixed;
	cout.precision(1);
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << -1 << '\n';
	}
	else {
		cout << 1 << '\n';
		cout << a << ' ' << b << ' ' << c << '\n';
	}

	return 0;
}