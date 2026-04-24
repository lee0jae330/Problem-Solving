#include<bits/stdc++.h>

using namespace std;

int arr[101];
int N,K,A,B;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K >> A >> B;
	for (int i = 0; i < N; i++) {
		arr[i] = K;
	}
	int day = 0;
	while (1) {
		int idx = A* (day++ %(N/A));
		for (int i = 0; i < A; i++) {
			arr[idx+i] += B;
		}
		for (int i = 0; i < N; i++) {
			arr[i]--;
			if (!arr[i]) {
				cout << day <<'\n';
				return 0;
			}
		}
		
	}
}