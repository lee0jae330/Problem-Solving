// *g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int N, M;

int arr[1001][1001];
int visited[1001][1001];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0) {
				tx = N - 1;
			}
			if (ty < 0) {
				ty = M - 1;
			}
			if (tx >= N) {
				tx = 0;
			}
			if (ty >= M) {
				ty = 0;
			}

			if (visited[tx][ty] || arr[tx][ty]) {
				continue;
			}
			visited[tx][ty] = 1;
			q.push({ tx,ty });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && !arr[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}