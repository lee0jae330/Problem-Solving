#include <bits/stdc++.h>

using namespace std;

int round(int n, int m, int k) {
  if (m == k) {
    return n;
  }

  int tmp = n % (int)(pow(10, m));

  if (tmp == n) {
    return n;
  }

  n -= tmp;
  if (tmp >= 5 * pow(10, m - 1)) {
    n += pow(10, m);
  }
  return round(n, m + 1, k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;

  while (N--) {
    int num;
    cin >> num;

    cout << round(num, 1, to_string(num).length()) << '\n';
  }
  return 0;
}