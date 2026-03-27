#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    stack<string> s;

    ll sol = 0;

    for (char c : str) {
        string tmp(1, c);

        if (s.empty()) {
            if (!(tmp == "(" || tmp == "[")) {
                cout << 0 << '\n';
                return 0;
            }
            s.push(tmp);
            continue;
        }

        if (tmp == "(" || tmp == "[") {
            s.push(tmp);
            continue;
        }

        ll sum = 0;
        if (tmp == ")") {
            while (1) {
                if (s.empty()) {
                    cout << 0 << '\n';
                    return 0;
                }

                string t = s.top();

                if (t == "(") {
                    if (!sum) {
                        sum += 2;
                    } else {
                        sum *= 2;
                    }
                    s.pop();
                    break;
                } else if (t == "[") {
                    cout << 0 << '\n';
                    return 0;
                }
                ll num = stoll(t);
                sum += num;
                s.pop();
            }
            s.push(to_string(sum));
        } else {
            while (1) {
                if (s.empty()) {
                    cout << 0 << '\n';
                    return 0;
                }

                string t = s.top();

                if (t == "[") {
                    if (!sum) {
                        sum += 3;
                    } else {
                        sum *= 3;
                    }
                    s.pop();
                    break;
                } else if (t == "(") {
                    cout << 0 << '\n';
                    return 0;
                }
                ll num = stoll(t);
                sum += num;
                s.pop();
            }
            s.push(to_string(sum));
        }
    }

    while (!s.empty()) {
        string t = s.top();
        if (t[0] >= '0' && t[0] <= '9') {
            sol += stoll(t);
        } else {
            cout << 0 << '\n';
            return 0;
        }
        s.pop();
    }

    cout << sol << '\n';
    return 0;
}