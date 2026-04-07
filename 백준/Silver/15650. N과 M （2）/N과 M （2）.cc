#include <bits/stdc++.h>

using namespace std;

int N, M;

int visited[9];

vector<int> v;

void rec(int x, int cnt) {
    if (cnt == M) {
        for (int num : v) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = x; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            v.push_back(i);
            rec(i + 1, cnt + 1);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    rec(1, 0);
    return 0;
}