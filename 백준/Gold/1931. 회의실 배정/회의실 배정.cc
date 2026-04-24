#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v;

bool comp1(pair<int, int>p1, pair<int, int>p2) { // 끝나는 시간 오름차순
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}



int main(void) {
	fastio();
	int N=100000;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a=i, b=i+1;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), comp1);
	int s, e;
	int cnt = 1;
	int idx = 0;
	s = v[0].first, e = v[0].second;
	for (int i = 1; i < N; i++) {
		if (v[i].first < e)
			continue;
		else {
			cnt++;
			e = v[i].second;
		}
	}
	cout << cnt << '\n';
	

	return 0;
}