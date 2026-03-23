#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    deque<int> dq;
    while (N--) {
        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "push_front") {
            cin >> x;
            dq.push_front(x);
        } else if (cmd == "push_back") {
            cin >> x;
            dq.push_back(x);
        } else if (cmd == "pop_front") {
            if (dq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (cmd == "size") {
            cout << dq.size() << '\n';
        } else if (cmd == "empty") {
            cout << (int)dq.empty() << '\n';
        } else if (cmd == "front") {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        } else if (cmd == "back") {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        }
    }
}