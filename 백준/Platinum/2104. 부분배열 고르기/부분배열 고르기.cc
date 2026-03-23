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

    s.emplace(v[0], v[0]);  // min값, sum
    ll sol = 0;

    for (int i = 1; i < N; i++) {
        ll prevSum = 0;
        while (1) {
            if (s.empty()) {
                s.emplace(v[i], prevSum + v[i]);
                break;
            }
            auto [minValue, sum] = s.top();
            if (minValue < v[i]) {
                s.emplace(v[i], prevSum + v[i]);
                break;
            } else {
                prevSum += sum;
                sol = max(sol, minValue * prevSum);
                s.pop();
            }
        }
    }

    ll prevSum = 0;
    while (!s.empty()) {
        auto [minValue, sum] = s.top();
        prevSum += sum;
        sol = max(sol, minValue * prevSum);
        s.pop();
    }

    cout << sol << '\n';
    return 0;
}