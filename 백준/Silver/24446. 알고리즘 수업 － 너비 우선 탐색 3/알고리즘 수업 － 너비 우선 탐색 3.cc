#include<bits/stdc++.h>

using namespace std;

vector<int>v[100001];

int visited[100001];

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (visited[v[x][i]] != -1) {
				continue;
			}
			visited[v[x][i]] = visited[x] +1;
			q.push(v[x][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(visited,visited+100001,-1);

	int N,M,R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs(R);

	for (int i = 1; i <= N; i++) {
		cout << visited[i]<<'\n';
	}
	return 0;
}