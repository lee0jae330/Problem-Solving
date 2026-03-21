#include <bits/stdc++.h>

using namespace std;

stack<int> s;
vector<char> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int num = 1;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (s.empty()) {
            if (num > x) {
                cout << "NO" << '\n';
                return 0;
            }
            while (num <= x) {
                s.push(num++);
                v.push_back('+');
            }
            s.pop();
            v.push_back('-');
        } else {
            int t = s.top();
            if (t == x) {
                s.pop();
                v.push_back('-');
            } else if (t < x) {
                while (num <= x) {
                    s.push(num++);
                    v.push_back('+');
                }
                s.pop();
                v.push_back('-');
            } else {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    for (char c : v) {
        cout << c << '\n';
    }
    return 0;
}