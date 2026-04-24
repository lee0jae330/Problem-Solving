#include<bits/stdc++.h>

using namespace std;

int main() {
	int W,H;
	cin >> W >> H;
	double result = (double)W * (double)H / 2.0;
	cout << fixed;
	cout.precision(1);
	cout << result <<'\n';
	return 0;
}