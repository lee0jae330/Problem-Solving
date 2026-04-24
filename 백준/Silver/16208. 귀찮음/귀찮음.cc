#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int> v;

int main(void) {
	fastio();
	int N;
	cin >> N;
	long long int total=0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		total += a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	long long int sum=0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i] * (total - v[i]);
		total -= v[i];
	}
	cout << sum << "\n";
	return 0;
}