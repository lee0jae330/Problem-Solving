#include <bits/stdc++.h>

using namespace std;

int N, M;

int visited[1001][2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    while (M--) {
        int x, y;
        cin >> x >> y;
        visited[y][x] = 1;
    }

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    visited[0][0] = 1;

    int sol = -1;

    while (!q.empty()) {
        auto [x, y, num] = q.front();
        if (x == 0 && y == 2 * N) {
            cout << num << '\n';
            return 0;
        }
        q.pop();

        for (auto [xx, yy] : {make_pair(1, 1), {-1, 1}}) {
            int tx = x + xx, ty = y + yy;
            if (tx < 0 || ty < 0 || tx > N || ty > 2 * N || visited[tx][ty]) {
                continue;
            }
            visited[tx][ty] = 1;
            q.emplace(tx, ty, max(num, tx));
        }
    }

    cout << -1 << '\n';
    return 0;
}
