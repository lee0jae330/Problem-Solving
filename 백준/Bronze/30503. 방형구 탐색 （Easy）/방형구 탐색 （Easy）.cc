#include <iostream>

using namespace std;

int arr[1001];
int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int num;
        cin >> num;
        if (num == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            int cnt = 0;
            for (int i = l - 1; i < r; i++) {
                if (arr[i] == k) {
                    cnt++;
                }
            }
            cout << cnt << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            for (int i = l - 1; i < r; i++) {
                arr[i] = 0;
            }
        }
    }
    return 0;
}