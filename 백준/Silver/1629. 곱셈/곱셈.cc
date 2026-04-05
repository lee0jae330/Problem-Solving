#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A, B, C;

ll rec(int x, int y, int z) {
    if (y == 1) {
        return x % z;
    }

    if (y % 2) {
        return (rec(x, y - 1, z) * (x % z) % z);
    }

    return ((rec(x, y / 2, z) % z) * (rec(x, y / 2, z) % z) % z);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B >> C;

    cout << rec(A, B, C) << '\n';
    return 0;
}