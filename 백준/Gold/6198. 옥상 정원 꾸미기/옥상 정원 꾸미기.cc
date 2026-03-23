#include <bits/stdc++.h>

using namespace std;

vector<int> v;
stack<int> s;

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

    long long sol = 0;

    for (int i = 0; i < N; i++) {
        while (true) {
            if (s.empty()) {
                s.push(v[i]);
                break;
            }

            if (s.top() > v[i]) {
                sol += s.size();
                s.push(v[i]);
                break;
            } else {
                s.pop();
            }
        }
    }

    cout << sol << '\n';
    return 0;
}