#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int cost[1001];
int acc[1001];

vector<int>v[1001];

int indegree[1001];

void reset() {
	memset(indegree, 0, sizeof(indegree));
	memset(acc, 0, sizeof(acc));

	for (int i = 0; i < 1001; i++) {
		v[i].clear();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		reset();

		int N, K;
		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;

			v[x].push_back(y);

			indegree[y]++;
		}

		int W;
		cin >> W;

		int f = 0;

		queue<pair<int, int>>qq;
		int c[1001] = { 0, };

		for (int i = 1; i <= N; i++) {
			if (!indegree[i]) {
				if (i == W) {
					f = 1;
					cout << cost[i] << '\n';
					break;
				}

				qq.push({ i,0 });
				acc[i] = cost[i];
			}
		}

		if (f) {
			continue;
		}

		while (!qq.empty()) {
			auto [x, depth] = qq.front();

			if (x == W) {
				cout << acc[x] << '\n';
				break;
			}
			qq.pop();

			for (int tx : v[x]) {
				indegree[tx]--;
				acc[tx] = max(acc[tx], cost[tx] + acc[x]);
				if (!indegree[tx]) {
					qq.push({ tx, depth + 1 });
				}
			}
		}
	}


	return 0;
}