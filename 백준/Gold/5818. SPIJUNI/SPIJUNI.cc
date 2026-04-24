#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int parent[1001];
bool check;

void init() {
	for (int i = 0; i < 1001; i++) {
		parent[i] = i;
	}
}

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	check = false;
	if (x != y) {
		check = true;
		if (x > y)
			parent[x] = y;
		else
			parent[y] = x;
	}
}

vector<pair<pair<int, int>, int>>v;

bool comp(pair<pair<int, int>,int>p1, pair<pair<int, int>,int>p2) {
	return p1.second < p2.second;
}

int main(void) {
	fastio();
	init();
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cost;
			cin >> cost;
			if (i > j)
				v.push_back({ {i,j},cost });
		}
	}
	for (int i = 1; i <= N; i++) {
		int cost;
		cin >> cost;
		v.push_back({ {0,i},cost });
	}
	sort(v.begin(), v.end(), comp);
	long long result = 0;
	for (int i = 0; i < v.size(); i++) {
		merge(v[i].first.first, v[i].first.second);
		if (check)
			result += v[i].second;
	}
	cout << result << '\n';
	return 0;
}