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

  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  int tmp = v[N - 1];
  int cnt = 1;
  for (int i = N - 2; i >= 0; i--) {
    if (v[i] > tmp) {
      cnt++;
      tmp = v[i];
    }
  }

  cout << cnt << '\n';
  return 0;
}