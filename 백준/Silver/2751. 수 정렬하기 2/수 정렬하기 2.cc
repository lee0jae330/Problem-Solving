#include<bits/stdc++.h>

using namespace std;

int arr[1000001];
int tmp[1000001];
int N;

void merge(int st,int en) {
	int mid = (st+en) / 2;
	int s_idx = st, e_idx = mid;

	for (int i = st; i < en; i++) {
		if (s_idx == mid) 
			tmp[i]= arr[e_idx++];
		else if(e_idx == en)
			tmp[i] = arr[s_idx++];
		else if (arr[s_idx] <= arr[e_idx]) {
			tmp[i]=arr[s_idx++];
		}
		else {
			tmp[i]=arr[e_idx++];
		}
	}
	for (int i = st; i < en; i++) {
		arr[i]=tmp[i];
	}
}

void merge_sort(int st, int en) {
	if(st == en-1)
		return;
	int mid = (st+en) / 2;
	merge_sort(st,mid);
	merge_sort(mid,en);
	merge(st,en);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	merge_sort(0,N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] <<'\n';
	}
	return 0;
}