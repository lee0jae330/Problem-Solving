#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[501][501];
int visited[501][501];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

int bfs(int x, int y) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = 1;
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty] || !arr[tx][ty]) {
                continue;
            }

            q.emplace(tx, ty);
            visited[tx][ty] = 1;
        }
    }
    return cnt;
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

    int cnt = 0;
    int sol = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] && !visited[i][j]) {
                cnt++;
                sol = max(sol, bfs(i, j));
            }
        }
    }
    cout << cnt << '\n' << sol << '\n';
    return 0;
}