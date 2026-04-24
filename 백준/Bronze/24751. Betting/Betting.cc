#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	double p;
	cin >> p;
	double a = 100. - p;
	cout.precision(12);
	cout << 100. / p << '\n';
	cout << 100. / a << '\n';
	return 0;
}