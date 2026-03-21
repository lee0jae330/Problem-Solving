#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    vector<int> arr(11, 0);
    for (char c : str) {
        arr[c - '0']++;
    }

    int sol = (arr[6] + arr[9]) / 2;

    if ((arr[6] + arr[9]) % 2) {
        sol++;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) {
            continue;
        }
        sol = max(sol, arr[i]);
    }

    cout << sol << '\n';
    return 0;
}
