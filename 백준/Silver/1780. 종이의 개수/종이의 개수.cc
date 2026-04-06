#include <bits/stdc++.h>

using namespace std;

int N;

int arr[2188][2188];

int sol[3];

void rec(int n, int x, int y) {
    if (n == 1) {
        switch (arr[x][y]) {
            case -1:
                sol[0]++;
                break;
            case 0:
                sol[1]++;
                break;
            case 1:
                sol[2]++;
        }
        return;
    }

    int flag = -100;
    int f = 0;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (flag == -100) {
                flag = arr[i][j];
            } else if (flag != arr[i][j]) {
                f = 1;
                break;
            }
        }
    }

    if (!f) {
        switch (flag) {
            case -1:
                sol[0]++;
                break;
            case 0:
                sol[1]++;
                break;
            case 1:
                sol[2]++;
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            rec(n / 3, x + i * n / 3, y + j * n / 3);
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