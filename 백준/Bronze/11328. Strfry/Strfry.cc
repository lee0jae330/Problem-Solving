#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    while (N--) {
        string a, b;
        cin >> a >> b;
        int arr1[26] =
            {
                0,
            },
            arr2[26] = {
                0,
            };
        for (char c : a) {
            arr1[c - 'a']++;
        }

        for (char c : b) {
            arr2[c - 'a']++;
        }

        int flag = 0;

        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            cout << "Possible" << '\n';
        } else {
            cout << "Impossible" << '\n';
        }
    }
    return 0;
}