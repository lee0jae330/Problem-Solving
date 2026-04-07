#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> arr, v;

int visited[10001];

void rec(int idx, int cnt) {
    if (cnt == M) {
        for (int num : v) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[arr[i]]) {
            visited[arr[i]] = 1;
            v.push_back(arr[i]);
            rec(i + 1, cnt + 1);
            v.pop_back();
            visited[arr[i]] = 0;
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