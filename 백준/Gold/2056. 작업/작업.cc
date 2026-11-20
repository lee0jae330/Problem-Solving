#include<bits/stdc++.h>

using namespace std;

int arr[10001];
int cost[10001];

vector<int> v[10001];

int indegree[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N ;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int t, num;
		cin >> t >> num;

		arr[i] = cost[i] = t;

		while (num--) {
			int x;
			cin >> x;
			v[x].push_back(i);
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
			cost[tx] = max(cost[tx], arr[tx]+cost[x]);
			if (!indegree[tx]) {
				q.push(tx);
			}
		}
	}

	int mx = 0;
	for (int i = 1; i <= N; i++) {
		mx = max(mx, cost[i]);
	}
	cout << mx <<'\n';
	return 0;
} 