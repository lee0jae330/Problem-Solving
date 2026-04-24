#define _USE_MATH_DEFINES

#include<iostream>
#include<math.h>
using namespace std;

double pi = 3.141593;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	double n;
	cin >> n;
	double result1 = n * n * pi;
	double result2 = 4 * n * n /2 ;
	cout << fixed;
	cout.setf(ios::showpoint);
	cout.precision(6);
	cout << M_PI*pow(n,2) <<"\n";
	cout << fixed;

	cout.setf(ios::showpoint);
	cout.precision(6);
	cout << 2*pow(n,2) << "\n";
	return 0;
}