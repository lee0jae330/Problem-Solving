#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int x;
    cin >> x;

    sort(v.begin(), v.end());

    int left = 0, right = N - 1;
    int cnt = 0;
    while (left < right) {
        int sum = v[left] + v[right];
        if (sum >= x) {
            right--;
            if (sum == x) {
                cnt++;
            }
        } else {
            left++;
        }
    }
    cout << cnt << '\n';
    return 0;
}