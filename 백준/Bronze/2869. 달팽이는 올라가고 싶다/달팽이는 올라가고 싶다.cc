#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	fastio();
	int A, B, V;
	cin >> A >> B >> V;
	int num = A - B;
	int sol = V - A;
	int result = sol / num;
	if (sol % num)
		result++;
	result++;
	cout << result << '\n';
	return 0;
}