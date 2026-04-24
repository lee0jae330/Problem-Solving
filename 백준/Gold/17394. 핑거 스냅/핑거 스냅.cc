// *g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int N, A, B;

int prime[1000001];
int visited[1000001];

void bfs(int x) {
	int cnt = 0;
	queue<pair<int,int>>q;
	q.push({x,cnt});
	visited[x] = 1;

	while (!q.empty()) {
		tie(x,cnt) = q.front();
		q.pop();
		if (A <= x && x <= B && !prime[x]) {
			cout << cnt << '\n';
			return;
		}
		int tx = x / 2;
		if (!visited[tx]) {
			visited[tx] = 1;
			q.push({ tx,cnt + 1 });
		}
		tx = x / 3;
		if (!visited[tx]) {
			visited[tx] = 1;
			q.push({ tx,cnt + 1 });
		}
		tx = x + 1;
		if (tx <= 1000000 && !visited[tx]) {
			q.push({ tx,cnt+1});
			visited[tx] = 1;
		}
		tx = x - 1;
		if (tx >= 0&&!visited[tx]) {
			visited[tx] = 1;
			q.push({ tx,cnt + 1 });
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	prime[1] = 1;

	for (int i = 2; i <= sqrt(1000000); i++) {
		if (prime[i])
			continue;
		for (int j = i + i; j <= 1000000; j += i) {
			prime[j] = 1;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		cin >> N >> A >> B;
		bfs(N);
	}
	return 0;
}