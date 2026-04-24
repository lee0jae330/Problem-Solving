#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int arr[50001];

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init() {
	for (int i = 0; i < 50001; i++)
		arr[i] = i;
}

int main(void) {
	fastio();
	init();
	for (int i = 1; i < 50001; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	int N;
	cin >> N;
	cout << arr[N] << "\n";
	return 0;
}