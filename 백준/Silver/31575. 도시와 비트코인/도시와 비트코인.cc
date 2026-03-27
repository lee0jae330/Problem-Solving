#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[301][301];
int visited[301][301];

int xx[2] = {0, 1};
int yy[2] = {1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visited[0][0] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == M - 1 && y == N - 1) {
            cout << "Yes" << '\n';
            return 0;
        }

        for (int i = 0; i < 2; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= M || ty >= N || visited[tx][ty] || !arr[tx][ty]) {
                continue;
            }

            visited[tx][ty] = 1;
            q.emplace(tx, ty);
        }
    }

    cout << "No" << '\n';
    return 0;
}