#include <bits/stdc++.h>

using namespace std;

int N, M;

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
        v.push_back(i);
        rec(i, cnt + 1);
        v.pop_back();
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