#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v(5);
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }

    for (int i = 1;; i++) {
        int cnt = 0;
        for (int n : v) {
            if (i % n == 0) {
                cnt++;
            }
        }

        if (cnt >= 3) {
            cout << i;
            return 0;
        }
    }
}