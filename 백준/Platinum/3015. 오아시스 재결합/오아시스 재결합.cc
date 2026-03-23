#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> v;
stack<pair<int, ll>> s;

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
    long long sol = 0;
    for (int i = 1; i < N; i++) {
        ll cnt = 0;
        while (1) {
            if (s.empty()) {
                sol += cnt;
                s.emplace(v[i], cnt + 1);
                break;
            }

            auto [t, num] = s.top();

            if (t > v[i]) {
                sol += cnt + 1;
                s.emplace(v[i], cnt + 1);
                break;
            } else if (t < v[i]) {
                sol += num;
                s.pop();
            } else {
                cnt += num;
                s.pop();
            }
        }
    }

    cout << sol << '\n';
    return 0;
}