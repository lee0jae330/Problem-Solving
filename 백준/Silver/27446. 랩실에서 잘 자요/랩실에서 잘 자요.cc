#include<bits/stdc++.h>

using namespace std;

int N,M;
set<int> s;
int arr[101];
int visited[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (auto iter = s.begin(); iter != s.end(); iter++) {
		arr[*iter]=1;
	}

	vector<int>v;
	int sol =0;
	for (int i = 1; i <= N; i++) {
		v.clear();
		if (!arr[i]&&!visited[i]) {
			visited[i]=1;
			v.push_back(i);
			int tmp = i;
			for (int j = i + 1; j <= N; j++) {
				if (!arr[j]) {
					if (j <= tmp + 3) {
						v.push_back(j);
						visited[j] = 1;
						tmp = j;
					}
					else {
						int sz = v[v.size()-1] - v[0] +1;
						sol += (5+2*sz);
						v.clear();
						break;
					}
				}
			}
			if (!v.empty()) {
				int sz = v[v.size() - 1] - v[0] + 1;
				sol += (5 + 2 * sz);
			}
		}
	}
	cout << sol <<'\n';
	return 0;
}