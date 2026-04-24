#include<iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	int a = N * 0.78, b = N * 0.8 + N * 0.2 * 0.78;
	cout << a << ' ' << b << '\n';
	return 0;
}