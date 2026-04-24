#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	fastio();
	long long w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	w1 = max(w1, w2);
	h1 += h2;
	cout << w1 * 2 + (h1 + 2) * 2;
	return 0;
}