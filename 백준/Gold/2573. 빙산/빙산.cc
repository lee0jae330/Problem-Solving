#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[301][301];
int visited[301][301];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = 1;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty] || !arr[tx][ty]) {
                continue;
            }
            q.emplace(tx, ty);
            visited[tx][ty] = 1;
        }
    }
}

void melt() {
    int cp[301][301] = {
        0,
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cnt = 0;
            if (arr[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int tx = i + xx[k], ty = j + yy[k];
                    if (!arr[tx][ty]) {
                        cnt++;
                    }
                }
            }
            cp[i][j] = max(arr[i][j] - cnt, 0);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = cp[i][j];
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

    int sol = 0;
    while (1) {
        memset(visited, 0, sizeof(visited));

        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        if (!cnt) {
            cout << 0 << '\n';
            return 0;
        } else if (cnt >= 2) {
            cout << sol << '\n';
            return 0;
        }

        melt();

        sol++;
    }
    return 0;
}