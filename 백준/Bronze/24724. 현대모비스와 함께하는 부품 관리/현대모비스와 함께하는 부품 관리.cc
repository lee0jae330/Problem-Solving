#include<iostream>
#include<cmath>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	int num = 1;
	while (T--) {
		int N;
		cin >> N;
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
		}
		cout << "Material Management " << num++ << '\n';
		cout << "Classification ---- End!" << '\n';
	}
	return 0;
}