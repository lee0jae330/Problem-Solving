#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int s,g,p,d;
	cin >> s >> g >> p >> d;
	int sol = 0;
	int pre,cur;
	for (int i = 0; i < N; i++) {
		char mvp;
		cin >> mvp;
		int money;
		if (i == 0) {
			if (mvp == 'B') {
				money = s-1;
			}
			else if(mvp=='S') {
				money = g-1;
			}
			else if (mvp == 'G') {
				money = p-1;
			}
			else if (mvp == 'P') {
				money = d-1;
			}
			else {
				money = d;
			}
			sol += money;
			pre = money;
		}
		else {
			if (mvp == 'B') {
				money = s - 1;
			}
			else if (mvp == 'S') {
				money = g - 1;
			}
			else if (mvp == 'G') {
				money = p - 1;
			}
			else if (mvp == 'P') {
				money = d - 1;
			}
			else {
				money = d;
			}
			if (money == d) {
				sol += money;
				pre = money;
			}
			else {
				money -= pre;
				sol += money;
				pre = money;
			}
			
		}
		//cout << money <<'\n';
	}
	cout << sol <<'\n';
	return 0;
}