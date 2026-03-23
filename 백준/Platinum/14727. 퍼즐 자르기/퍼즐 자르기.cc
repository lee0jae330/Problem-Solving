#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> v;
stack<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    s.emplace(v[0], 1);
    ll sol = 0;

    for (int i = 1; i < N; i++) {
        int cnt = 0;
        while (1) {
            if (s.empty()) {
                s.emplace(v[i], cnt + 1);
                break;
            }

            auto [t, num] = s.top();
            if (t < v[i]) {
                s.emplace(v[i], cnt + 1);
                break;
            } else {
                cnt += num;
                sol = max(sol, (ll)t * (ll)cnt);
                s.pop();
            }
        }
    }

    int cnt = 0;
    while (!s.empty()) {
        auto [t, num] = s.top();
        cnt += num;
        sol = max(sol, (ll)t * (ll)cnt);
        s.pop();
    }
    cout << sol << '\n';
    return 0;
}