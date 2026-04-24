#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<pair<int, int>, int>>v;
bool check;
int parent[10001];

void init() {
	for (int i = 0; i < 10001; i++)
		parent[i] = i;
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

bool comp(pair<pair<int, int>, int>p1, pair<pair<int, int>, int>p2) {
	return p1.second < p2.second;
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T > 0) {
		init();
		v.clear();
		int N, M, p, q;
		long long pq = 0;
		long long result = 0;
		cin >> N >> M >> p >> q;
		if (p > q)
			swap(p, q);
		for (int i = 0; i < M; i++) {
			int a, b, cost;
			cin >> a >> b>>cost;
			if (a > b)
				swap(a, b);
			if (a == p && b == q) {
				merge(a, b);
				pq += cost;
			}
			v.push_back({ {a,b},cost });
		}
		sort(v.begin(), v.end(), comp);
		for (int i = 0; i < v.size(); i++) {
			merge(v[i].first.first, v[i].first.second);
			if (check)
				pq += v[i].second;
		}
		init();
		for (int i = 0; i < v.size(); i++) {
			merge(v[i].first.first, v[i].first.second);
			if (check)
				result += v[i].second;
		}
		if (result == pq)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		T--;
	}
}