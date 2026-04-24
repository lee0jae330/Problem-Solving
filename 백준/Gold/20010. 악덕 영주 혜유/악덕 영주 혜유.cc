#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<pair<int, int>, int>> v;
int parent[1001];
bool check = false;
vector<pair<int, int>>graph[1001];
int visited[1001];



void init() {
	for (int i = 0; i < 1001; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	check = false;
	if (x != y) {
		if (x > y)
			parent[x] = y;
		else
			parent[y] = x;
		check = true;
	}
}

bool comp(pair<pair<int, int>, int>p1, pair<pair<int, int>, int > p2) {
	return p1.second < p2.second;
}

int maxdist, maxnode;

void dfs(int x, int d) {
	if (visited[x])
		return;
	if (maxdist < d) {
		maxnode = x;
		maxdist = d;
	}
	visited[x] = 1;
	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i].first;
		int nextdist = graph[x][i].second;
		dfs(next, nextdist + d);
	}
}

int main(void) {
	fastio();
	init();
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		v.push_back({ {a,b},cost });
	}
	sort(v.begin(), v.end(),comp);
	int result = 0;
	for (int i = 0; i < K; i++) {
		merge(v[i].first.first, v[i].first.second);
		if (check) {
			result += v[i].second;
			graph[v[i].first.first].push_back({ v[i].first.second,v[i].second });
			graph[v[i].first.second].push_back({ v[i].first.first,v[i].second });
		}
	}
	dfs(0, 0);
	memset(visited, 0, sizeof(visited));
	dfs(maxnode, 0);
	cout << result << '\n';
	cout << maxdist << '\n';
	return 0;
}