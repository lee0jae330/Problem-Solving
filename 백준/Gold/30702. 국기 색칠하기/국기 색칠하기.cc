#include <bits/stdc++.h>

using namespace std;

int N, M;

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

char arr1[51][51];
char arr2[51][51];
char cp[51][51];

int visited[51][51];

void bfs(int x, int y, char color) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = 1;
    cp[x][y] = color;

    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty] || arr1[x][y] != arr1[tx][ty]) {
                continue;
            }

            visited[tx][ty] = 1;
            cp[tx][ty] = color;
            q.emplace(tx, ty);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int x = 0; x < 2; x++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!x) {
                    cin >> arr1[i][j];
                    cp[i][j] = arr1[i][j];
                } else {
                    cin >> arr2[i][j];
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && arr1[i][j] != arr2[i][j]) {
                bfs(i, j, arr2[i][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cp[i][j] != arr2[i][j]) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    cout << "YES" << '\n';
    return 0;
}