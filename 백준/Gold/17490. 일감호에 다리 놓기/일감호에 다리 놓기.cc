#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int parent[1000001];
bool check;
vector<pair<pair<int, int>, int>> v;
map<int, int>m;
set<int>s;
void init() {
	for (int i = 0; i < 1000001; i++) {
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
	long long K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		int cost;
		cin >> cost;
		v.push_back({ {0,i},cost });
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		if (a == 1 && b == N)
			s.insert(N);
		else
			s.insert(a);
		
	}

	for (int i = 1; i <= N; i++) {
		if (s.find(i) != s.end())
			continue;
		if (i != N)
			merge(i, i + 1);
		else
			merge(N, 1);
	}
	int tmp = Find(1);
	int flag = 0;

	for (int i = 2; i <= N; i++) {
		if (tmp != Find(i)) {
			flag = 1;
			break;
		}
	}
	long long result = 0;
	if (flag) {
		for (int i = 0; i < v.size(); i++) {
			merge(v[i].first.first, v[i].first.second);
			if (check) {
				result += v[i].second;
			}
		}
	}
	if (K >= result)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}