#include<iostream>
#include<vector>
#include<memory.h>
#include<string.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

vector<pair<int, int>> v;
int arr[51];

int main(void) {
	fastio();
	//memset(arr, 1, sizeof(arr));

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int w, h;
		cin >> w >> h;
		v.push_back({ w,h });
	}

	for (int i = 0; i < N; i++) {
		int w = v[i].first, h = v[i].second;
		arr[i] = 1;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (v[j].first > w && v[j].second > h) {
				arr[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i];
		if (i < N - 1)
			cout << ' ';
	}
	cout << '\n';
	return 0;
}