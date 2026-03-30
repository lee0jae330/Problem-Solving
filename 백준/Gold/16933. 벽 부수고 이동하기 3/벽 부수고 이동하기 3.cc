#include <bits/stdc++.h>

using namespace std;

int N, M, K;

char arr[1001][1001];
int visited[1001][1001][2][11];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
    int cnt = 0;
    int isNight = 0;

    queue<tuple<int, int, int, int>> q;
    q.emplace(x, y, isNight, cnt);
    visited[x][y][isNight][cnt] = 1;

    while (!q.empty()) {
        tie(x, y, isNight, cnt) = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1) {
            cout << visited[x][y][isNight][cnt] << '\n';
            return;
        }

        if (!visited[x][y][!isNight][cnt] || visited[x][y][!isNight][cnt] > visited[x][y][isNight][cnt] + 1) {
            visited[x][y][!isNight][cnt] = visited[x][y][isNight][cnt] + 1;
            q.emplace(x, y, !isNight, cnt);
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
                continue;
            }

            if (arr[tx][ty] == '0') {
                if (!visited[tx][ty][!isNight][cnt] || visited[tx][ty][!isNight][cnt] > visited[x][y][isNight][cnt] + 1) {
                    visited[tx][ty][!isNight][cnt] = visited[x][y][isNight][cnt] + 1;
                    q.emplace(tx, ty, !isNight, cnt);
                }
            } else {
                // 낮 일때
                if (!isNight) {
                    if (cnt + 1 <= K && (!visited[tx][ty][!isNight][cnt + 1] || visited[tx][ty][!isNight][cnt + 1] > visited[x][y][isNight][cnt] + 1)) {
                        visited[tx][ty][!isNight][cnt + 1] = visited[x][y][isNight][cnt] + 1;
                        q.emplace(tx, ty, !isNight, cnt + 1);
                    }
                } else if (!visited[x][y][!isNight][cnt] || visited[x][y][!isNight][cnt] > visited[x][y][isNight][cnt] + 1) {
                    visited[x][y][!isNight][cnt] = visited[x][y][isNight][cnt] + 1;
                    q.emplace(x, y, !isNight, cnt);
                }
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    bfs(0, 0);
    return 0;
}