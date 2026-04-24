#include<iostream>
#include<string>
#include<math.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}


int main(void) {
	fastio();
	long long int M = 1234567891;
	long long int r = 31;
	string str;
	int L;
	cin >> L;
	cin >> str;
	long long int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		long long int n = str[i] - 'a' + 1; 
		long long int tmp;
		if(i<7)
			tmp = n * pow(31, i);
		else {
			long long int mod = i % 7;
			long long int div = i / 7;
			long long int n1 = n * pow(31, mod);
			n1 %= M;
			long long int xx = pow(31, 7);
			xx %= M;
			long long int result = 1;
			for (int j = 0; j < div; j++) {
				result *= xx;
				result %= M;
			}
			tmp = result*n1;
		}
		tmp %= M;
		sum += tmp;
		sum %= M;
	}
	sum %= M;
	cout << sum<<'\n';
	return 0;
}