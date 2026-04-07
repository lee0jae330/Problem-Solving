#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> arr, v;

int visited[9];

set<vector<int>> s;

void rec(int x, int cnt) {
    if (cnt == M) {
        if (s.find(v) != s.end()) {
            return;
        }
        s.insert(v);
        for (int num : v) {
            cout << num << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = x; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            v.push_back(arr[i]);
            rec(i + 1, cnt + 1);
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

    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    rec(0, 0);
    return 0;
}