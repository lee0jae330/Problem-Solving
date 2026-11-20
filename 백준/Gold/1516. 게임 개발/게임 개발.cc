#include<bits/stdc++.h>

using namespace std;

int arr[501];
int cost[501];

vector<int>v[501];

int indegree[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int x, y, z;
		cin >> x >> y;

		arr[i] = x;
		cost[i] = x;

		if (y == -1) {
			continue;
		}

		v[y].push_back(i);
		indegree[i]++;
		while (1) {
			cin >> z;
			if (z == -1) {
				break;
			}
			v[z].push_back(i);
			indegree[i]++;
		}
	}

	queue<int>q;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int tx : v[x]) {
			indegree[tx]--;
			cost[tx] = max(cost[tx], arr[tx] + cost[x]);
			if (!indegree[tx]) {
				q.push(tx);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << cost[i] << '\n';
	}

	return 0;

}