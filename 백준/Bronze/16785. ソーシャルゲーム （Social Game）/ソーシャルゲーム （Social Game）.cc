#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int a, b, c;
	cin >> a >> b >> c;
	int total = 0;
	int cnt = 0,day=0;
	for (int i = 0; i < 1000000; i++) {
		if (cnt == 6) {
			total += b;
			cnt = -1;
		}
		total += a;
		cnt++;
		day++;
		if (total >= c)
			break;
	}
	cout << day << '\n';
}