#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll A, B;
  cin >> A >> B;

  cout << B + 1 + ((B + 1) * (B) * (A - 2)) / 2 << '\n';
  return 0;
}