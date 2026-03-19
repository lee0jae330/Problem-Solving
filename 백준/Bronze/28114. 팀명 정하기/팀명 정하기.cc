#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, string>> v;

bool comp1(const tuple<int, int, string>& a, const tuple<int, int, string>& b) {
    auto [x1, y1, z1] = a;
    auto [x2, y2, z2] = b;
    return (y1 % 100) < (y2 % 100);
}

bool comp2(const tuple<int, int, string>& a, const tuple<int, int, string>& b) {
    auto [x1, y1, z1] = a;
    auto [x2, y2, z2] = b;
    return x1 > x2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 3; i++) {
        int x, y;
        string z;
        cin >> x >> y >> z;

        v.push_back({x, y, z});
    }
    sort(v.begin(), v.end(), comp1);

    for (auto [x, y, z] : v) {
        cout << y % 100;
    }
    cout << '\n';
    sort(v.begin(), v.end(), comp2);

    for (auto [x, y, z] : v) {
        cout << z[0];
    }

    return 0;
}
