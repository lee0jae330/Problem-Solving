#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> v;
int visited[61][61][61];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> tmp = v;
    for (int i = 0; i < 3 - N; i++) {
        tmp.push_back(0);
    }
    visited[tmp[0]][tmp[1]][tmp[2]] = 1;
    queue<tuple<int, int, int, int>> q;
    q.emplace(tmp[0], tmp[1], tmp[2], 0);
    while (!q.empty()) {
        auto [x, y, z, cnt] = q.front();
        q.pop();

        if (!x && !y && !z) {
            cout << cnt << '\n';
            return 0;
        }

        vector<int> perm = {0, 1, 2};
        do {
            vector<int> tmp = {x, y, z};

            int num = 9;
            for (int i = 0; i < 3; i++) {
                int idx;
                for (int j = 0; j < 3; j++) {
                    if (i == perm[j]) {
                        idx = j;
                    }
                }

                if (!tmp[idx]) {
                    continue;
                }

                tmp[idx] = max(tmp[idx] - num, 0);

                if (num == 9) {
                    num = 3;    
                } else if (num == 3) {
                    num = 1;
                }
            }

            int tx = tmp[0], ty = tmp[1], tz = tmp[2];
            if (!visited[tx][ty][tz]) {
                q.emplace(tx, ty, tz, cnt + 1);
                visited[tx][ty][tz] = 1;
            }
        } while (next_permutation(perm.begin(), perm.end()));
    }

    return 0;
}
