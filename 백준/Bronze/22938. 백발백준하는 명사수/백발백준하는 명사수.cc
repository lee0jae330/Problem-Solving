#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	long long a, b, r1,x,y,r2;
	cin >> a >> b >> r1 >> x >> y >> r2;
	r1 += r2;
	if ((double)r1 > sqrt((double)pow(a - x, 2) + (double)pow(b - y, 2)))
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}