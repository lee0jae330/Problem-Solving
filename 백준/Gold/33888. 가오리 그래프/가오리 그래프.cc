#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v[51];
int visited[51];

int bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (v[x].size() != 2 && v[x].size() != 1) {
            return x;
        }
        for (int tx : v[x]) {
            if (!visited[tx]) {
                q.push(tx);
                visited[tx] = 1;
            }
        }
    }
    return 0;
}

vector<pair<int, int>> bfs1(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    vector<pair<int, int>> tmp;
    while (!q.empty()) {
        int xx = q.front();
        q.pop();
        if (x != xx && (v[xx].size() == 3 || v[xx].size() == 4)) {
            tmp.emplace_back(xx, v[xx].size());
            continue;
        }
        for (int tx : v[xx]) {
            if (!visited[tx]) {
                q.push(tx);
                visited[tx] = 1;
            }
        }
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N + 3; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int x;
    set<int> sol;
    for (int i = 1; i <= N; i++) {
        int sz = v[i].size();
        if (sz == 1) {
            x = i;
            sol.insert(i);
        } else if (sz != 2) {
            sol.insert(i);
        }
    }
    sol.erase(x);
    int y = bfs(x);
    sol.erase(y);

    memset(visited, 0, sizeof(visited));
    auto tmp = bfs1(y);
    int B = -1, C = -1, D = -1;
    for (auto [x, y] : tmp) {
        sol.erase(x);
        if (y == 4) {
            C = x;
        } else {
            if (D == -1) {
                D = x;
            } else {
                B = x;
                if (B > D) {
                    swap(B, D);
                }
            }
        }
    }

    for (int num : sol) {
        cout << num << ' ';
    }
    cout << B << ' ' << C << ' ' << D << ' ' << y << ' ' << x << '\n';
    return 0;
}