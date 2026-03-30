#include <bits/stdc++.h>

using namespace std;

int R, C;

char arr[1501][1501];
int visited[1501][1501];
int ice[1501][1501];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

vector<pair<int, int>> swan;

int sx, sy, ex, ey;

queue<pair<int, int>> q;
queue<pair<int, int>> next_melt_ice;

int flag = 0;

void bfs() {
    set<pair<int, int>> s;
    while (!q.empty()) {
        auto [x, y] = q.front();
        if (x == ex && y == ey) {
            flag = 1;
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= R || ty >= C) {
                continue;
            }

            if (arr[tx][ty] == 'X') {
                s.emplace(tx, ty);
                continue;
            }

            if (arr[tx][ty] == '.' && !visited[tx][ty]) {
                visited[tx][ty] = 1;
                q.emplace(tx, ty);
            }
        }
    }
    for (auto p : s) {
        q.push(p);
    }
}

void findIce(int x, int y) {
    queue<pair<int, int>> qq;
    qq.emplace(x, y);
    visited[x][y] = 1;
    while (!qq.empty()) {
        tie(x, y) = qq.front();
        qq.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= R || ty >= C || visited[tx][ty]) {
                continue;
            }

            if (arr[tx][ty] == '.' && !ice[x][y]) {
                next_melt_ice.emplace(x, y);
                ice[x][y] = 1;
            }

            if (arr[tx][ty] == 'X' && !visited[tx][ty]) {
                qq.emplace(tx, ty);
                visited[tx][ty] = 1;
            }
        }
    }
}

void melt() {
    queue<pair<int, int>> nq;
    while (!next_melt_ice.empty()) {
        auto [x, y] = next_melt_ice.front();
        next_melt_ice.pop();
        arr[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= R || ty >= C) {
                continue;
            }

            if (arr[tx][ty] == 'X' && !ice[tx][ty]) {
                nq.emplace(tx, ty);
                ice[tx][ty] = 1;
            }
        }
    }
    next_melt_ice = nq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'L') {
                swan.emplace_back(i, j);
                arr[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'X' && !visited[i][j]) {
                findIce(i, j);
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    tie(sx, sy) = swan.front();
    tie(ex, ey) = swan.back();

    q.emplace(sx, sy);

    int day = 0;
    while (1) {
        bfs();
        if (flag) {
            cout << day << '\n';
            return 0;
        }
        melt();
        day++;
    }
    return 0;
}