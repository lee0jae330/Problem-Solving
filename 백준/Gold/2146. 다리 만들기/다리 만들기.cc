#include <bits/stdc++.h>

using namespace std;

int N;

int arr[101][101];
int visited[101][101];
int dist[101][101];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

void bfs(int x, int y, int color) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = color;

    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N || visited[tx][ty] || !arr[tx][ty]) {
                continue;
            }
            q.emplace(tx, ty);
            visited[tx][ty] = color;
        }
    }
}

int buildBridge(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    dist[x][y] = 0;
    int color = visited[x][y];
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N || dist[tx][ty] != -1 || visited[tx][ty] == color) {
                continue;
            }

            if (!arr[tx][ty]) {
                dist[tx][ty] = dist[x][y] + 1;
                q.emplace(tx, ty);
            } else if (visited[tx][ty] != color) {
                return dist[x][y];
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int color = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] && !visited[i][j]) {
                bfs(i, j, color++);
            }
        }
    }

    int sol = INT_MAX;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) {
                for (int i = 0; i < N; i++) {
                    fill(dist[i], dist[i] + 101, -1);
                }
                int result = buildBridge(i, j);
                if (result != -1) {
                    sol = min(sol, result);
                }
            }
        }
    }
    cout << sol << '\n';
    return 0;
}