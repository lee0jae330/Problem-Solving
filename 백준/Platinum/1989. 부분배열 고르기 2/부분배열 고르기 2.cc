#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> v;
stack<tuple<int, ll, int, int>> s;

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

    s.emplace(v[0], v[0], 1, 1);  // min값, sum, i, j
    ll sol = 0;
    int solStart = 1, solEnd = 1;

    for (int i = 1; i < N; i++) {
        ll prevSum = 0, prevStart = 0, prevEnd = 0;
        while (1) {
            if (s.empty()) {
                s.emplace(v[i], prevSum + v[i], prevStart ? prevStart : i + 1, i + 1);
                break;
            }
            auto [minValue, sum, start, end] = s.top();
            if (minValue < v[i]) {
                s.emplace(v[i], prevSum + v[i], prevStart ? prevStart : i + 1, i + 1);
                break;
            } else {
                prevSum += sum;
                if (!prevEnd) {
                    prevEnd = end;
                }
                ll tmp = minValue * prevSum;
                if (sol < tmp) {
                    sol = tmp;
                    solStart = start;
                    solEnd = prevEnd;
                }
                sol = max(sol, minValue * prevSum);
                prevStart = start;
                s.pop();
            }
        }
    }

    ll prevSum = 0, prevStart = 0, prevEnd = 0;
    while (!s.empty()) {
        auto [minValue, sum, start, end] = s.top();
        prevSum += sum;
        if (!prevEnd) {
            prevEnd = end;
        }
        ll tmp = minValue * prevSum;

        if (sol < tmp) {
            sol = tmp;
            solStart = start;
            solEnd = prevEnd;
        }
        s.pop();
    }

    cout << sol << '\n';
    cout << solStart << ' ' << solEnd << '\n';
    return 0;
}