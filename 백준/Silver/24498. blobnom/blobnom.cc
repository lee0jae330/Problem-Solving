#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000001];

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	fastio();
	int N;
	int sol = -1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sol = max(arr[i], sol);
	}
	for (int i = 1; i < N-1; i++) {
		int left = arr[i - 1];
		int right = arr[i + 1];
		int now = arr[i];
		int tmp = min(left, right);
			sol = max(sol, tmp + now);
	}
	cout << sol << "\n";
	return 0;
}