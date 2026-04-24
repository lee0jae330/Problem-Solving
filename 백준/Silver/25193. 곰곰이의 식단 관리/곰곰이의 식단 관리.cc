#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N, ck=0, f=0;
	cin >> N;
	while (N--) {
		char c;
		cin >> c;
		if (c == 'C')
			ck++;
		else
			f++;
	}
	if (!ck) {
		cout << ck << '\n';
	}
	else {
		if (!f)
			cout << ck << '\n';
		else {
			f++;
			if (ck < f)
				cout << 1 << '\n';
			else {
				int tmp = ck / f;
				if (ck % f)
					tmp++;
				cout << tmp << '\n';
			}
		}
	}
	return 0;
}