#include<bits/stdc++.h>

using namespace std;

vector<int>v[1001];
int indegree[1001];

int cost[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	while (M--) {
		int A, B;
		cin >> A >> B;

		v[A].push_back(B);
		indegree[B]++;
	}

	queue<int>q;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) {
			q.push(i);
			cost[i] = 1;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int tx : v[x]) {
			indegree[tx]--;
			cost[tx] = max(cost[tx], 1 + cost[x]);

			if (!indegree[tx]) {
				q.push(tx);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << cost[i] << ' ';
	}
	cout << '\n';

}