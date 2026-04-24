#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, A, B;
  cin >> N >> M >> A >> B;

  int tmp = N * 3 - M;
  if (tmp <= 0) {
    cout << 0 << '\n';
    return 0;
  }
  cout << tmp * A + B << '\n';
  return 0;
}