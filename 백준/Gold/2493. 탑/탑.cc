#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> sol;
stack<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    v.resize(N);
    sol.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sol[0] = 0;
    s.emplace(v[0], 0);

    for (int i = 1; i < N; i++) {
        int value, idx;
        while (1) {
            if (s.empty()) {
                sol[i] = 0;
                s.emplace(v[i], i);
                break;
            }
            tie(value, idx) = s.top();

            if (value < v[i]) {
                s.pop();
            } else {
                s.emplace(v[i], i);
                sol[i] = idx + 1;
                break;
            }
        }
    }

    for (int num : sol) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}