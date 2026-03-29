#include <bits/stdc++.h>

using namespace std;

int K, W, H;

int arr[201][201];
int visited[201][201][31];

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

int xxx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int yyy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int x, int y) {
    int cnt = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(x, y, cnt);
    visited[x][y][cnt] = 1;

    while (!q.empty()) {
        tie(x, y, cnt) = q.front();
        q.pop();

        if (x == H - 1 && y == W - 1) {
            cout << visited[x][y][cnt] - 1 << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + xx[i], ty = y + yy[i];
            if (tx < 0 || ty < 0 || tx >= H || ty >= W || visited[tx][ty][cnt] || arr[tx][ty]) {
                continue;
            }

            q.emplace(tx, ty, cnt);
            visited[tx][ty][cnt] = visited[x][y][cnt] + 1;
        }

        for (int i = 0; i < 8; i++) {
            int tx = x + xxx[i], ty = y + yyy[i];
            if (tx < 0 || ty < 0 || tx >= H || ty >= W || arr[tx][ty]) {
                continue;
            }

            if (cnt + 1 <= K && !visited[tx][ty][cnt + 1]) {
                q.emplace(tx, ty, cnt + 1);
                visited[tx][ty][cnt + 1] = visited[x][y][cnt] + 1;
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
        }
    }
    bfs(0, 0);
    return 0;
}