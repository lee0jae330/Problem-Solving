#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int parent[200002];
bool check;
vector < pair<pair<int, int>, int>>v;

void init() {
	for (int i = 0; i < 200002; i++) {
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

bool comp(pair<pair<int, int>, int>p1, pair<pair<int, int>, int>p2) {
	return p1.second < p2.second;

}

int main(void) {
	fastio();
	init();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}
	long long int result = 0;
	for (int i = 1; i <= N; i++) {
		int  a;
		cin >> a;
		v.push_back({ {0,i},a });
	}
	sort(v.begin(), v.end(), comp);

	long long int tmp = 0;
	for (int i = 0; i < v.size(); i++) {
		merge(v[i].first.first, v[i].first.second);
		if (check) {
			tmp += v[i].second;
		}
	}
	cout << tmp << '\n';
	return 0;
}