#include <bits/stdc++.h>

using namespace std;

int N;

int col[15];
int sol = 0;

bool isValid(int row) {
    for (int i = 0; i < row; i++) {
        if (col[row] == col[i]) {
            return false;
        }

        if (abs(row - i) == abs(col[row] - col[i])) {
            return false;
        }
    }
    return true;
}

void backtrack(int row) {
    if (row == N) {
        sol++;
        return;
    }

    for (int i = 0; i < N; i++) {
        col[row] = i;
        if (isValid(row)) {
            backtrack(row + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    backtrack(0);

    cout << sol << '\n';
    return 0;
}