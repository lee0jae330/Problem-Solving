#include<bits/stdc++.h>

using namespace std;

int main() {
	int w1,w2,h1,h2;
	cin >> w1 >> h1 >> w2 >> h2;
	int sol = 0;
	int flag = 0;
	if (w1 >= w2 && h1 >= h2) {
		int tmp = w1; 
		int cnt =0;
		while (tmp / 2 >= w2) {
			tmp = tmp / 2 + (tmp % 2);
			cnt++;
		}
		if (tmp > w2) {
			cnt++;
		}
		tmp =h1;
		while (tmp / 2 >= h2) {
			tmp = tmp / 2 + (tmp % 2);
			cnt++;
		}
		if (tmp > h2) {
			cnt++;
		}
		flag=1;
		sol = cnt;
	}
	if (w1 >= h2 && h1 >= w2) {
		int tmp = w1;
		int cnt = 0;
		while (tmp / 2 >= h2) {
			tmp = tmp / 2 + (tmp % 2);
			cnt++;
		}
		if (tmp > h2) {
			cnt++;
		}
		tmp = h1;
		while (tmp / 2 >= w2) {
			tmp = tmp / 2 + (tmp % 2);
			cnt++;
		}
		if (tmp > w2) {
			cnt++;
		}
		if (flag) {
			sol = min(sol, cnt);
		}
		else {
			sol = cnt;
			
		}
		flag = 1;
	}
	if (flag) {
		cout << sol<<'\n';
	}
	else {
		cout << -1<<'\n';
	}
	return 0;
}