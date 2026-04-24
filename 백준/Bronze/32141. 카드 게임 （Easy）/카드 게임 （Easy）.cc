#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, H;
  cin >> N >> H;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < N; i++) {
    H -= v[i];
    if (H <= 0) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';

  return 0;
}