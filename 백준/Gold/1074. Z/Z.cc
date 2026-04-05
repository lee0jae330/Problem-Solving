#include <bits/stdc++.h>

using namespace std;

int N, r, c;

int rec(int n, int x, int y) {
    if (n == 1) {
        return 2 * x + y;
    }

    int tmp = (1 << (n - 1));
    return (2 * (x / tmp) + y / tmp) * (1 << (2 * n - 2)) + rec(n - 1, x % tmp, y % tmp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> r >> c;

    cout << rec(N, r, c) << '\n';

    return 0;
}
