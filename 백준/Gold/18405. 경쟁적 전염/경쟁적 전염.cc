#include<bits/stdc++.h>

using namespace std;

int N, K, S, X,Y;

int arr[201][201];
int visited[1001][201][201];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

queue<pair<int, int>>q;


void bfs(int num) {
	while (!q.empty()) {
		auto[x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N||visited[num][tx][ty]!=-1) {
				continue;
			}
			visited[num][tx][ty] = visited[num][x][y] + 1;
			q.push({ tx,ty });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(visited, -1, sizeof(visited));

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> S >> X >> Y;
	for (int n = 1; n <= K; n++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == n) {
					q.push({ i,j });
					visited[n][i][j] = 0;
				}
			}
		}
		bfs(n);
	}




	int tmp = 0, sol = -1;

	for (int n = 1; n <= K; n++) {
		if (visited[n][X-1][Y-1]!=-1&&visited[n][X - 1][Y - 1] <= S) {
			if (sol == -1) {
				sol = visited[n][X - 1][Y - 1];
				tmp = n;
			}
			else {
				if (sol > visited[n][X - 1][Y - 1]) {
					sol = visited[n][X - 1][Y - 1];
					tmp = n;
				}
			}
		}
	}
	cout << tmp << '\n';
	return 0;
}