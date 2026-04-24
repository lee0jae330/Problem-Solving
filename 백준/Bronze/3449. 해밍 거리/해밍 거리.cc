#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    string x, y;
    cin >> x >> y;

    int sum = 0;
    for (int i = 0; i < x.length(); i++) {
      if (x[i] != y[i]) {
        sum++;
      }
    }
    cout << "Hamming distance is " << sum << ".\n";
  }
  return 0;
}