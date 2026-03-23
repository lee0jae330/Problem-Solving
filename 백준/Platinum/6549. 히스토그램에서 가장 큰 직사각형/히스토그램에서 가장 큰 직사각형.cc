#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1) {
        int N;
        cin >> N;
        if (!N) {
            return 0;
        }
        v.resize(N);
        stack<pair<int, int>> s;
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        s.emplace(v[0], 1);
        ll sol = 0;

        for (int i = 1; i < N; i++) {
            ll cnt = 0;
            while (1) {
                if (s.empty()) {
                    s.emplace(v[i], cnt + 1);
                    break;
                }

                auto [value, num] = s.top();

                if (value < v[i]) {
                    s.emplace(v[i], cnt + 1);
                    break;
                } else {
                    cnt += num;
                    sol = max(sol, value * cnt);
                    s.pop();
                }
            }
        }

        ll prevCnt = 0;
        while (!s.empty()) {
            auto [value, num] = s.top();
            prevCnt += num;
            sol = max(sol, prevCnt * value);
            s.pop();
        }

        cout << sol << '\n';
    }
}