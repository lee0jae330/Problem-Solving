#include<iostream>

using namespace std;

int arr[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}

	int T, P;
	cin >> T >> P;
	int sum = 0;
	for (int n : arr) {
		sum += (n / T + (n % T ? 1 : 0));
	}

	cout << sum <<'\n';
	cout << N / P << ' ' << N % P <<'\n';
	return 0;
}