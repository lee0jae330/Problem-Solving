#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;

	cin >> A >> B;
	int left = 0, right = 0;
	while (1) {
		if (A == 1 && B == 1) {
			cout << right << ' ' << left << '\n';
			return 0;
		}

		if (A == 1) {
			left +=  B -A;
			A = 1, B = 1;
			continue;
		}

		if (B == 1) {
			right += A - B;
			A = 1, B = 1;
			continue;
		}

		if (A > B) {
			right += A / B;
			A %= B;
		}
		else {
			left+= B/A;
			B %= A;
		}
	}
	return 0;
}