#include<bits/stdc++.h>

using namespace std;

int N, M, A, B, K;

int arr[501][501];
int visited[501][501];

int sx, sy, ex, ey;

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		if (x == ex && y == ey) {
			cout << visited[x][y] << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx <= 0 || ty <= 0 || tx > N || ty > M||visited[tx][ty]!=-1) {
				continue;
			}
			int flag = 0;
			for (int j = 0; j < B; j++) {
				if (ty + j > M) {
					flag = 1;
					break;
				}
					
				if (arr[tx][ty + j]) {
					flag = 1;
				}
			}
			if (flag)
				continue;
			for (int j = 0; j < A; j++) {
				if (tx + j > N) {
					flag = 1;
					break;
				}
				if (arr[tx + j][ty]) {
					flag = 1;
				}
			}
			if (flag)
				continue;
			for (int j = 0; j < A; j++) {
				if (tx + j > N) {
					flag = 1;
					break;
				}
				if (arr[tx + j][ty + B - 1]) {
					flag = 1;
				}
			}
			if (flag)
				continue;
			for (int j = 0; j < B; j++) {
				if (ty + j > M) {
					flag = 1;
					break;
				}
				if (arr[tx + A - 1][ty + j]) {
					flag = 1;
				}
			}
			if (flag)
				continue;
			visited[tx][ty] = visited[x][y] + 1;
			q.push({ tx,ty });
		}
	}
	cout << -1 << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(visited, -1, sizeof(visited));

	cin >> N >> M >> A >> B >> K;
	while (K--) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}

	

	cin >> sx >> sy;
	cin >> ex >> ey;
	bfs(sx, sy);
	return 0;
}