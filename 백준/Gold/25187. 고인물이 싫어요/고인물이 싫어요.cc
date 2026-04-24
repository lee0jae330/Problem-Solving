#include<iostream>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

const int SIZE = 1e5 + 1;
int parent[SIZE];
int ranking[SIZE];
map<int, pair<int, int>>m;

void init() {
	for (int i = 0; i < SIZE; i++) {
		parent[i] = i;
		ranking[i] = 0;
	}
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	if (ranking[x] < ranking[y]) {
		swap(x, y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	parent[y] = x;
	m[x].first += m[y].first;
	m[x].second += m[y].second;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	int N, M, Q;
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) {
		int water;
		cin >> water;
		m[i] = water ? make_pair(1, 0) : make_pair(0, 1);
	}

	while (M--) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
	}

	while (Q--) {
		int k;
		cin >> k;
		m[find(k)].first > m[find(k)].second ? cout << 1 << '\n' : cout << 0 << '\n';
	}
	return 0;
}
