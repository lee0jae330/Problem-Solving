#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K;
    cin >> K;

    while (K--) {
        int x;
        cin >> x;
        if (!x) {
            s.pop();
        } else {
            s.push(x);
        }
    }

    long long sol = 0;
    while (!s.empty()) {
        sol += s.top();
        s.pop();
    }

    cout << sol << '\n';

    return 0;
}
