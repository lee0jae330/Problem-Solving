#include<bits/stdc++.h>

using namespace std;

int N,M;
int A[1000001],B[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	int a_idx = 0;
	int b_idx = 0;
	for (int i = 0; i < N + M; i++) {
		if (a_idx >= N) {
			cout << B[b_idx++] <<' ';
		}
		else if (b_idx >= M) {
			cout << A[a_idx++] <<' ';
		}
		else {
			if (A[a_idx] <= B[b_idx]) {
				cout << A[a_idx++] <<' ';
			}
			else {
				cout << B[b_idx++] << ' ';
			}
		}
	}
	return 0;
}