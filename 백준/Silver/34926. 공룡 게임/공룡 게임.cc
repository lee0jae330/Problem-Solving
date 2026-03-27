#include <bits/stdc++.h>

using namespace std;

int N, K;
string str;
int visited[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    cin >> str;
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int x = q.front();
        if (x == N - 1) {
            cout << "YES" << '\n';
            return 0;
        }
        q.pop();

        for (int xx : {1, K}) {
            int tx = x + xx;
            if (tx >= N || visited[tx] || str[tx] == '#') {
                continue;
            }
            visited[tx] = 1;
            q.push(tx);
        }
    }
    cout << "NO" << '\n';
    return 0;
}