#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> sol;

stack<int> s;

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

    sol[N - 1] = -1;
    s.push(v[N - 1]);

    for (int i = N - 2; i >= 0; i--) {
        while (1) {
            if (s.empty()) {
                sol[i] = -1;
                s.push(v[i]);
                break;
            }

            if (s.top() > v[i]) {
                sol[i] = s.top();
                s.push(v[i]);
                break;
            } else {
                s.pop();
            }
        }
    }

    for (int num : sol) {
        cout << num << ' ';
    }

    cout << '\n';
    return 0;
}
