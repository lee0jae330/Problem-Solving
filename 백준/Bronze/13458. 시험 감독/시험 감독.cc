#include<bits/stdc++.h>

using namespace std;

int N, B, C;

vector<int>v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		v[i] -= B;
	}
	long long sol = v.size();
	for (int i = 0; i < N; i++) {
		if (v[i] <= 0)
			continue;
		sol += v[i] / C;
		if (v[i] % C) {
			sol++;
		}
	}
	cout << sol << '\n';
	return 0;
}