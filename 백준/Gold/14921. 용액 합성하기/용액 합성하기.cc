#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l = 0, r = N - 1;
    int sol = 2 * 1e8 + 1;
    while (l < r) {
        int tmp = arr[l] + arr[r];

        if (abs(sol) > abs(tmp)) {
            sol = tmp;
        }

        if (tmp < 0) {
            l++;
        } else {
            r--;
        }
    }

    cout << sol << '\n';
    return 0;
}