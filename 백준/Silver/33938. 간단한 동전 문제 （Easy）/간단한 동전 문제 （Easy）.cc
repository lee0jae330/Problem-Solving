#include <bits/stdc++.h>

using namespace std;

int N, M;

int visited[4001];

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    queue<pair<int, int>> q;
    visited[2000] = 1;
    q.emplace(2000, 0);

    while (!q.empty()) {
        auto [x, cnt] = q.front();
        q.pop();
        if (x == M + 2000) {
            cout << cnt << '\n';
            return 0;
        }

        for (int xx : v) {
            int tx = x + xx;

            if (tx < 0 || tx > 4000 || visited[tx]) {
                continue;
            }
            visited[tx] = 1;
            q.emplace(tx, cnt + 1);
        }
    }
    cout << -1 << '\n';
    return 0;
}