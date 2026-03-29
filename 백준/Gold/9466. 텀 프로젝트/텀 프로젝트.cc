#include <bits/stdc++.h>

using namespace std;

int N;

int arr[100001];
int visited[100001];
int finished[100001];

int sol;

void dfs(int x) {
    visited[x] = 1;
    int nxt = arr[x];

    if (!visited[nxt]) {
        dfs(nxt);
    } else if (!finished[nxt]) {
        // 사이클 끝났는지에 대한 여부
        for (int cur = nxt; cur != x; cur = arr[cur]) {
            sol++;
        }
        sol++;
    }
    finished[x] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;

        sol = 0;
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << N - sol << '\n';
    }
    return 0;
}