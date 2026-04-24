#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<long long> v;

int main(void) {
	fastio();
	int N;
	cin >> N;
	long long a1;
	cin >> a1;
	for (int i = 0; i < N - 1; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (a1 > v[i]) {
			a1 += v[i];
		}
		
		else {
			cout << "No" << '\n';
			return 0;
		}
	}
	cout << "Yes" << '\n';
	return 0;

}