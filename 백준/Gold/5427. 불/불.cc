#include <bits/stdc++.h>

using namespace std;

int w, h;

char arr[1001][1001];
int visited[1001][1001];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        for (int i = 0; i < 1001; i++) {
            fill(visited[i], visited[i] + 1001, -1);
        }
        queue<pair<int, int>> tmpQ;
        q = tmpQ;

        cin >> w >> h;
        int sx, sy;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    sx = i, sy = j;
                    arr[i][j] = '.';
                } else if (arr[i][j] == '*') {
                    q.emplace(i, j);
                    visited[i][j] = 0;
                    arr[i][j] = '.';
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int tx = x + xx[i], ty = y + yy[i];
                if (tx < 0 || ty < 0 || tx >= h || ty >= w || visited[tx][ty] != -1 || arr[tx][ty] == '#') {
                    continue;
                }
                q.emplace(tx, ty);
                visited[tx][ty] = visited[x][y] + 1;
            }
        }

        q.emplace(sx, sy);
        visited[sx][sy] = 0;

        int sol = -1;
        int flag = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int tx = x + xx[i], ty = y + yy[i];
                if (tx < 0 || ty < 0 || tx >= h || ty >= w) {
                    sol = visited[x][y] + 1;
                    flag = 1;
                    break;
                }

                if (arr[tx][ty] == '#') {
                    continue;
                }

                if (visited[tx][ty] == -1 || visited[tx][ty] > visited[x][y] + 1) {
                    q.emplace(tx, ty);
                    visited[tx][ty] = visited[x][y] + 1;
                }
            }
            if (flag) {
                break;
            }
        }
        cout << (sol == -1 ? "IMPOSSIBLE" : to_string(sol)) << '\n';
    }
    return 0;
}