#include<iostream>
#include<stdlib.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[101];

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int gap = 123456789;
	int sol = -1;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int now = arr[i] + arr[j] + arr[k];
			
				if (now<=M&&abs(M - now) < gap) {
					sol = now;
					gap = abs(M - now);
				}
			}
		}
	}
	cout << sol << '\n'; 
	return 0;
}