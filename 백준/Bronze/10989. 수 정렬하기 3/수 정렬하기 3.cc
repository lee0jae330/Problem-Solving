#include<bits/stdc++.h>

using namespace std;

int arr[10001];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		if (arr[i]) {
			for (int j = 0; j < arr[i]; j++)
				cout << i << '\n';
		}
	}
	return 0;
}