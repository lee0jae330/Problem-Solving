#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> cur(N);
  vector<int> prev(M);

  for (int i = 0; i < N; i++) {
    cin >> cur[i];
  }

  for (int i = 0; i < M; i++) {
    cin >> prev[i];
  }

  int sol = 0;
  for (int i = 0; i < M; i++) {
    if (i >= N) {
      sol = max(prev[i], sol);
      continue;
    }

    if (prev[i] > cur[i]) {
      sol = max(prev[i] - cur[i], sol);
    }
  }

  cout << sol << '\n';
  return 0;
}
