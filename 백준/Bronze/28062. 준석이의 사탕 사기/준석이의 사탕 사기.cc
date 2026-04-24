#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  v.resize(N);

  int sum = 0;

  for (int i = 0; i < N; i++) {
    cin >> v[i];
    sum += v[i];
  }

  if (sum % 2 == 0) {
    cout << sum << '\n';
    return 0;
  }

  int sol = 0;

  for (auto num : v) {
    int tmp = sum - num;
    if (tmp && tmp % 2 == 0) {
      sol = max(sol, tmp);
    }
  }
  cout << sol << '\n';
  return 0;
}