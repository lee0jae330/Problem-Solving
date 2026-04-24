#include<bits/stdc++.h>

using namespace std;

int N;
int arr[1000001];
int tmp[1000001];

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int l = start;
	int r = mid;
	for (int i = start; i < end; i++) {
		if (l < mid && r < end) {
			if (arr[l] <= arr[r]) {
				tmp[i] = arr[l++];
			}
			else {
				tmp[i] = arr[r++];
			}
		}
		else if (l < mid) {
			tmp[i] = arr[l++];
		}
		else if (r < end) {
			tmp[i] = arr[r++];
		}
	}
	for (int i = start; i < end; i++) {
		arr[i] = tmp[i];
	}
}

void merge_sort(int start, int end) {
	if (start + 1 == end)
		return;
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	merge_sort(0, N);
	for (int i = N-1; i >=0; i--) {
		cout << arr[i] << '\n';
	}
	return 0;
}