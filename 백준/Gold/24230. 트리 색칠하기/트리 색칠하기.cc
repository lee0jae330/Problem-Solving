#include<iostream>
#include<vector>

using namespace std;

vector<int> v[200001];
int color[200001];
int visited[200001];
int cnt;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void dfs(int x, int now) {
	visited[x] = 1;
	if (now != color[x]) {
		cnt++;
		now = color[x];
	}
	for (int i = 0; i < v[x].size(); i++) {
		if (visited[v[x][i]])
			continue;
		dfs(v[x][i], now);
	}
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> color[i];
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	cout << cnt << '\n';
	return 0;
}