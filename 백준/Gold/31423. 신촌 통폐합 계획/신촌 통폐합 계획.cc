#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

int parent[500001];
int visited[500001];
vector<int> v[500001];

void dfs(int x) {
    visited[x] = 1;
    cout << arr[x - 1];

    int sz = v[x].size();
    for (int i = 0; i < sz; i++) {
        int tx = v[x][i];
        if (!visited[tx]) {
            dfs(tx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        parent[b] = a;

        v[a].push_back(b);
    }

    int start = 0;

    for (int i = 1; i <= N; i++) {
        if (!parent[i]) {
            start = i;
        }
    }

    dfs(start);
    return 0;
}