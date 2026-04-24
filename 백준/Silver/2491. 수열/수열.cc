#include<bits/stdc++.h>

using namespace std;

int arr[100001];

int dp1[100001];
int dp2[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp1[i]=1;
		dp2[i]=1;
	}

	int sol =dp1[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] >= arr[i - 1]) {
			dp1[i] = max(dp1[i], 1 + dp1[i - 1]);
		}
		sol = max(dp1[i], sol);

	}

	for (int i = 1; i < N; i++) {
		if (arr[i] <= arr[i - 1]) {
			dp2[i] = max(dp2[i],1+ dp2[i-1]);
		}
		sol = max(dp2[i], sol);
	}

	cout << sol <<'\n';
	return 0;
}