#include<bits/stdc++.h>

using namespace std;

deque<int>dq;

int arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int num =1;

	for (int i = N - 1; i >= 0; i--) {
		int cmd = arr[i];
		if (arr[i] == 1) {
			dq.push_front(num);
		}
		else if (arr[i] == 2) {
			int tmp = dq.front();
			dq.pop_front();
			dq.push_front(num);
			dq.push_front(tmp);
		}
		else {
			dq.push_back(num);
		}
		num++;
	}
	for (auto i : dq) {
		cout << i <<' ';
	}
	return 0;
}