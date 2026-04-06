#include <bits/stdc++.h>

using namespace std;

int N;
int arr[129][129];

int sol[2];

void rec(int n, int x, int y) {
    int tmp = -1;
    int f = 0;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (tmp == -1) {
                tmp = arr[i][j];
            } else if (tmp != arr[i][j]) {
                f = 1;
                break;
            }
        }
    }

    if (!f) {
        switch (tmp) {
            case 0:
                sol[0]++;
                break;
            case 1:
                sol[1]++;
        }
        return;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            rec(n / 2, x + i * (n / 2), y + j * (n / 2));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    rec(N, 0, 0);
    for (int n : sol) {
        cout << n << '\n';
    }
    return 0;
}