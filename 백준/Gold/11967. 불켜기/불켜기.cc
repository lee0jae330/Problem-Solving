#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[101][101];
int visited[101][101];

vector<pair<int, int>> v[101][101];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = 1;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (auto [i, j] : v[x][y]) {
            arr[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                int ti = i + xx[k], tj = j + yy[k];
                if (ti < 0 || tj < 0 || ti >= N || tj >= N) {
                    continue;
                }

                if (visited[ti][tj] && !visited[i][j]) {
                    visited[i][j] = 1;
                    q.emplace(i, j);
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N || !arr[tx][ty] || visited[tx][ty]) {
                continue;
            }

            q.emplace(tx, ty);
            visited[tx][ty] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        v[x - 1][y - 1].emplace_back(a - 1, b - 1);
    }
    arr[0][0] = 1;

    bfs(0, 0);

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}