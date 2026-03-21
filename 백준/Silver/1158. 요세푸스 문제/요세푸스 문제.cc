#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    list<int> l;
    for (int i = 1; i <= N; i++) {
        l.push_back(i);
    }

    vector<int> v;
    auto iter = l.begin();
    int cnt = 0;
    while (!l.empty()) {
        cnt++;
        if (iter == l.end()) {
            iter = l.begin();
        }
        if (cnt == K) {
            v.push_back(*iter);
            iter = l.erase(iter);
            cnt = 0;
            continue;
        }
        iter++;
    }
    cout << '<';
    for (int i = 0; i < N; i++) {
        cout << v[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << '>';
    return 0;
}