#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

map<int, int> s;
map <int, int>l;

int visited[101];

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty()) {
		x = q.front();
		int cnt = visited[x];
		q.pop();
		for (int i = 1; i <= 6;i++) {
			int tx = x + i;
			if (tx<=100) {
				if (!visited[tx]) {
					if (l.find(tx) != l.end() || s.find(tx) != s.end()) {
						visited[tx] = cnt + 1;
						if (l.find(tx) != l.end()) {
							tx = l[tx];
						}
						else {
							tx = s[tx];
						}
						if (!visited[tx]) {
							visited[tx] = cnt + 1;
							q.push(tx);

						}
						else {
							if (visited[tx] > cnt + 1) {
								visited[tx] = cnt + 1;
								q.push(tx);
							}
						}
					}
					else {
						visited[tx] = cnt + 1;
						q.push(tx);
					}
				}
				else {
					if (visited[tx] > cnt + 1) {
						if (l.find(tx) != l.end() || s.find(tx) != s.end()) {
							visited[tx] = cnt + 1;
							if (l.find(tx) != l.end()) {
								tx = l[tx];
							}
							else {
								tx = s[tx];
							}
							if (!visited[tx]) {
								visited[tx] = cnt + 1;
								q.push(tx);

							}
							else {
								if (visited[tx] > cnt + 1) {
									visited[tx] = cnt + 1;
									q.push(tx);
								}
							}
						}
						else {
							visited[tx] = cnt + 1;
							q.push(tx);
						}
					}
					
					else
						continue;
				}

			}
		}
	}
}

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		l.insert({ x,y });
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		s.insert({ u,v });
	}
	bfs(1);
	cout << visited[100]-1 << '\n';
	return 0;
}