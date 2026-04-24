#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    for (int i = 1;; i++) {
        if (a * i % b == 1) {
            cout << i << '\n';
            return 0;
        }
    }
}