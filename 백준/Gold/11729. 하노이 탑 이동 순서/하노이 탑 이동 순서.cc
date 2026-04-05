#include <bits/stdc++.h>

using namespace std;

void rec(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }

    rec(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    rec(6 - a - b, b, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    cout << (1 << N) - 1 << '\n';
    rec(1, 3, N);

    return 0;
}