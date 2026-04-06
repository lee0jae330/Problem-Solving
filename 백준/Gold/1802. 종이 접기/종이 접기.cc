#include <bits/stdc++.h>

using namespace std;

string str;

bool rec(int start, int len) {
    if (len == 3) {
        return str[start] != str[start + len - 1];
    }

    int l_start = start, r_start = start + len / 2 + 1;
    string l = str.substr(l_start, len / 2);
    string r = str.substr(r_start, len / 2);
    string tmp = r;

    reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < len / 2; i++) {
        if (l[i] == tmp[i]) {
            return false;
        }
    }

    return rec(start, len / 2) && rec(start + len / 2 + 1, len / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> str;

        if (str.size() == 1) {
            cout << "YES" << '\n';
        } else {
            int len = str.size();
            cout << (rec(0, len) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}