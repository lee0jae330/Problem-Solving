#include<bits/stdc++.h>

using namespace std;

int N,K,M;

vector<int>v[1001];

int student[10001][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int t;
			cin >> t;
			v[i].push_back(t);
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int p;
			cin >> p;
			student[i][p]=1;
		}
	}

	for (int i = 0; i < M; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			int flag = 0;
			for (auto a : v[j]) {
				if (!student[i][a]) {
					flag=1;
					break;
				}
			}
			if (!flag) {
				cnt++;
			}
		}
		cout << cnt <<'\n';
	}
	return 0;
}