#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int S1, S2;
	cin >> S1 >> S2;
	int flag = 0, flag1=0;
	for (int i = 0; i < S1; i++) {
		int tc, sol;
		cin >> tc >> sol;
		if (tc != sol) {
			flag = 1;
		}
	}
	for (int i = 0; i < S2; i++) {
		int tc, sol;
		cin >> tc >> sol;
		if (tc != sol)
			flag1 = 1;
	}
	if (!flag && !flag1)
		cout << "Accepted" << '\n';
	else if (flag)
		cout << "Wrong Answer" << '\n';
	else if (flag1)
		cout << "Why Wrong!!!" << '\n';
	return 0;
}