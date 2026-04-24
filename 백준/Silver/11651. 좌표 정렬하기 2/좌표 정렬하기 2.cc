#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>>v;
int N;

bool comp(pair<int, int>p1, pair<int, int>p2) {
	if(p1.second ==p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x>> y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end(),comp);
	for (auto a : v) {
		cout << a.first << ' '<< a.second<<'\n';
	}
	return 0;
}