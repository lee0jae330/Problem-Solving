#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
	if (a.first.first == b.first.first) {
		return a.first.second < b.first.second;
	}
	return a.first.first < b.first.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<pair<int,int>,int>>v(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = {{x,y} , i+1};
	}

	sort(v.begin(),v.end(),compare);

	for (int i = 0; i < N - 1; i++) {
		cout << v[i].second <<' ' << v[i + 1].second << '\n';
	}
	return 0;


}
