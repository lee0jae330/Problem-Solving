#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int score1 = 0, score2 = 0;
	int a;
	cin >> a;
	score1 += a * 3;
	cin >> a;
	score1 += a * 2;
	cin >> a;
	score1 += a;
	cin >> a;
	score2 += a * 3;
	cin >> a;
	score2 += a * 2;
	cin >> a;
	score2 += a;
	if (score1 > score2) {
		cout << 'A' << '\n';
	}
	else if (score1 < score2)
		cout << 'B' << '\n';
	else {
		cout << 'T' << '\n';
	}
	return 0;
}