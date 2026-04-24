//*g5 & #bfs & %ko & !@$me


#include<bits/stdc++.h>

using namespace std;

int arr[3100][3100];
int visited[3100][3100];

char field[51][51];

int N, M,K;
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

queue<pair<int, int>>q;

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= (N + 2 * K) || ty >= (M + 2 * K) || visited[tx][ty]!=-1) {
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

	memset(visited, -1, sizeof(visited));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> field[i][j];
		}
	}
	cin >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 'o') {
				q.push({ K + i,K + j });
				visited[K + i][K + j] = 0;
			}
		}
	}
	bfs();
	int cnt = 0;
	for (int i = 0; i < N + 2 * K; i++) {
		for (int j = 0; j < M + 2 * K; j++) {
			//cout << visited[i][j] << ' ';
			if (visited[i][j]!=-1&&visited[i][j] <= K) {
				cnt++;
			}
		}
		//cout << '\n';
	}
	cout << cnt << '\n';
	return 0;
}