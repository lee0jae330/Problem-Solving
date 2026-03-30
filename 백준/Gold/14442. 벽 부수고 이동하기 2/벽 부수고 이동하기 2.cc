#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char arr[1001][1001];
int visited[1001][1001][11];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
    int cnt = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(x, y, cnt);
    visited[x][y][cnt] = 1;

    while (!q.empty()) {
        tie(x, y, cnt) = q.front();
        if (x == N - 1 && y == M - 1) {
            cout << visited[x][y][cnt] << '\n';
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
                continue;
            }

            if (arr[tx][ty] == '0' && !visited[tx][ty][cnt]) {
                visited[tx][ty][cnt] = visited[x][y][cnt] + 1;
                q.emplace(tx, ty, cnt);
            } else if (cnt + 1 <= K && !visited[tx][ty][cnt + 1]) {
                visited[tx][ty][cnt + 1] = visited[x][y][cnt] + 1;
                q.emplace(tx, ty, cnt + 1);
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