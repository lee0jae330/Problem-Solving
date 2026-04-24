#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, w, l;
  int T = 1;
  while (1) {
    cin >> r;
    if (!r) {
      return 0;
    }
    cin >> w >> l;

    if (w * w + l * l <= 4 * r * r) {
      cout << "Pizza " << T++ << " fits on the table." << '\n';
    } else {
      cout << "Pizza " << T++ << " does not fit on the table." << '\n';
    }
  }
}