#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<pair<int, int>> v(3);

  for (int i = 0; i < 3; i++) {
    cin >> v[i].first >> v[i].second;
  }

  int H;
  cin >> H;

  for (int i = 0;; i++) {
    for (auto p : v) {
      if (!i || i % p.first == 0) {
        H -= p.second;
        if (H <= 0) {
          cout << i << '\n';
          return 0;
        }
      }
    }
  }
  return 0;
}