#include <bits/stdc++.h>

using namespace std;

int N, M;
char arr[101][101];
int visited[101][101];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];

            if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty] || arr[tx][ty] == '0') {
                continue;
            }

            visited[tx][ty] = visited[x][y] + 1;
            q.emplace(tx, ty);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    bfs(0, 0);
    cout << visited[N - 1][M - 1] << '\n';
    return 0;
}