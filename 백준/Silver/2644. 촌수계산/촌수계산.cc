#include<bits/stdc++.h>

using namespace std;

vector<int>v[101];
int visited[101];

void bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	visited[x]=1;
	while (!q.empty()) {
		x = q.front();
		int d = visited[x];
		q.pop();
		if (x == y) {
			cout << d-1 <<'\n';
			return;
		}
		for (int i = 0; i < v[x].size(); i++) {
			if(visited[v[x][i]])
				continue;
			visited[v[x][i]]=d+1;
			q.push(v[x][i]);
		}
	}
	cout << -1 <<'\n';
}

int main() {
	int N;
	int a, b;
	cin >> N;
	cin >> a >> b;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(a,b);
	return 0;
}