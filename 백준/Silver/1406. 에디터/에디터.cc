#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;

    cin >> str;

    list<char> l;

    for (char c : str) {
        l.push_back(c);
    }

    auto iter = l.end();

    int N;
    cin >> N;
    while (N--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L' && iter != l.begin()) {
            iter--;
        } else if (cmd == 'D' && iter != l.end()) {
            iter++;
        } else if (cmd == 'B') {
            if (iter == l.begin()) {
                continue;
            }
            iter--;
            iter = l.erase(iter);
        } else if (cmd == 'P') {
            char c;
            cin >> c;
            l.insert(iter, c);
        }
    }

    for (char c : l) {
        cout << c;
    }

    return 0;
}