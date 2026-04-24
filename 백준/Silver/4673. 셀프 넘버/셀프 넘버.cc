#include<bits/stdc++.h>

using namespace std;

int arr[10001];

void check(int n) {
	if(n>10000)
		return;
	int tmp = n;
	while (n != 0) {
		int r = n % 10;
		tmp+=r;
		n/=10;
	}
	if (tmp <= 10000) {
		arr[tmp]=1;
		check(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) {
			cout << i <<'\n';
			check(i);
		}
	}
	return 0;
}