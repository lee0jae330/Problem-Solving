#include <bits/stdc++.h>

using namespace std;

vector<int> v;

set<vector<int>> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    v.resize(9);
    for (int i = 0; i < 9; i++) {
        cin >> v[i];
    }

    vector<int> tmp = v;

    visited.insert(tmp);
    queue<pair<vector<int>, int>> q;
    q.emplace(v, 0);

    while (!q.empty()) {
        auto [x, cnt] = q.front();
        q.pop();
        int flag = 0;
        for (int i = 0; i < 8; i++) {
            if (i + 1 != x[i]) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            cout << cnt << '\n';
            return 0;
        }

        int zero = -1;
        for (int i = 0; i < 9; i++) {
            if (!x[i]) {
                zero = i;
                break;
            }
        }

        for (auto [xx, yy] : {make_pair(-1, 0), {0, 1}, {1, 0}, {0, -1}}) {
            int xIdx = zero / 3, yIdx = zero % 3;

            int tx = xIdx + xx, ty = yIdx + yy;
            if (tx < 0 || ty < 0 || tx >= 3 || ty >= 3) {
                continue;
            }

            int idx = tx * 3 + ty;
            vector<int> tmp = x;
            swap(tmp[zero], tmp[idx]);
            if (visited.find(tmp) == visited.end()) {
                visited.insert(tmp);
                q.emplace(tmp, cnt + 1);
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}