#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T > 0) {
		unsigned long long N;
		cin >> N;
		if (N % 9 == 0 || N % 3 == 2)
			cout << "TAK" << '\n';
		else
			cout << "NIE" << '\n';
		T--;
	}
	return 0;
}