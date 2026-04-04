#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> v[11];

int cost[11];
int visited[11];

int bfs(int x, vector<int> comb) {
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    int color = comb[x - 1];

    int sum = 0;

    while (!q.empty()) {
        x = q.front();
        q.pop();
        sum += cost[x];
        for (int tx : v[x]) {
            if (!visited[tx] && comb[tx - 1] == color) {
                visited[tx] = 1;
                q.push(tx);
            }
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        v[i].resize(num);
        for (int j = 0; j < num; j++) {
            cin >> v[i][j];
        }
    }

    int sol = INT_MAX;

    for (int i = 1; i <= N / 2; i++) {
        vector<int> comb(N - i, 0);
        for (int x = 0; x < i; x++) {
            comb.push_back(1);
        }

        do {
            memset(visited, 0, sizeof(visited));
            vector<int> sum;
            for (int i = 1; i <= N; i++) {
                if (!visited[i]) {
                    sum.push_back(bfs(i, comb));
                }
            }

            if (sum.size() == 2) {
                sol = min(sol, abs(sum.front() - sum.back()));
            }
        } while (next_permutation(comb.begin(), comb.end()));
    }

    if (sol == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << sol << '\n';
    }
    return 0;
}