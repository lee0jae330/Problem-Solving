#include <bits/stdc++.h>

using namespace std;

int N, K;

int visited[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(visited, visited + 100001, -1);

    cin >> N >> K;

    visited[N] = 0;

    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int tx = 2 * x;
        if (tx <= 100000) {
            if (visited[tx] == -1 || visited[tx] > visited[x]) {
                visited[tx] = visited[x];
                q.push(tx);
            }
        }

        for (int xx : {1, -1}) {
            int tx = x + xx;
            if (tx < 0 || tx > 100000) {
                continue;
            }
            if (visited[tx] == -1 || visited[tx] > visited[x] + 1) {
                visited[tx] = visited[x] + 1;
                q.push(tx);
            }
        }
    }

    cout << visited[K] << '\n';
    return 0;
}