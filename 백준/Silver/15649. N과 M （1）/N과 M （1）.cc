#include <bits/stdc++.h>

using namespace std;

int N, M;

int visited[9];

vector<int> v;

void rec(int cnt) {
    if (cnt == M) {
        for (int n : v) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            v.push_back(i);
            rec(cnt + 1);
            visited[i] = 0;
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    rec(0);
    return 0;
}