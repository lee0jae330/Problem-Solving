//*g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int N, M;

int arr[51][51];
int visited[51][51];
int check[51][51];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty] != -1 || !arr[tx][ty]) {
				continue;
			}
			visited[tx][ty] = visited[x][y] + 1;
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
	int mx = -1;
	int sol = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visited,-1,sizeof(visited));
			if (arr[i][j]) {
				bfs(i,j);
				int start = arr[i][j];
				int end = 0, dist=-1;
				for (int r = 0; r < N; r++) {
					for (int c = 0; c < M; c++) {
						if (visited[r][c] != -1) {
							if (dist < visited[r][c]) {
								dist = visited[r][c];
								end = arr[r][c];
							}
							else if (dist == visited[r][c]) {
								end = max(end, arr[r][c]);
							}
						}
					}
				}
				if (mx < dist) {
					mx = dist;
					sol = start + end;
				}
				else if (mx == dist) {
					sol = max(sol, start+end);
				}
			}
		}
	}
	cout << sol <<'\n';
	return 0;
}
