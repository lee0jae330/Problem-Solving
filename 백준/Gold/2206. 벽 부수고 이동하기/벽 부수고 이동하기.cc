#include <bits/stdc++.h>

using namespace std;

char arr[1001][1001];
int visited[1001][1001][2];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

int N, M;

void bfs(int x, int y) {
    int flag = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(x, y, flag);
    visited[x][y][flag] = 1;

    while (!q.empty()) {
        tie(x, y, flag) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
                continue;
            }

            if (arr[tx][ty] == '1') {
                if (!flag && visited[tx][ty][!flag] == -1) {
                    visited[tx][ty][!flag] = visited[x][y][flag] + 1;
                    q.emplace(tx, ty, !flag);
                }
            } else {
                if (visited[tx][ty][flag] == -1) {
                    visited[tx][ty][flag] = visited[x][y][flag] + 1;
                    q.emplace(tx, ty, flag);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            fill(visited[i][j], visited[i][j] + 2, -1);
        }
    }

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    bfs(0, 0);
    int sol1 = visited[N - 1][M - 1][0], sol2 = visited[N - 1][M - 1][1];
    if (sol1 != -1 && sol2 != -1) {
        cout << min(sol1, sol2) << '\n';
    } else if (sol1 != -1) {
        cout << sol1 << '\n';
    } else if (sol2 != -1) {
        cout << sol2 << '\n';
    } else {
        cout << sol1 << '\n';
    }

    return 0;
}