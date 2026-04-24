//*g4 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int N, T, G;

int visited[100001];

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();

		if (x == G) {
			cout << visited[x] << '\n';
			return;
		}

		if (visited[x] >= T)
			continue;
		
		int tx = x + 1;
		if (tx <= 99999&&visited[tx] ==-1) {
			q.push(tx);
			visited[tx] = visited[x] + 1;
		}

		tx = 2 * x;
		if (tx > 99999)
			continue;
		int cnt = 0;
		int tmp = tx;
		while (tmp) {
			tmp /= 10;
			cnt++;
		}
		int num = 1;
		for (int i = 0; i < cnt - 1; i++) {
			num *= 10;
		}
		tx -= num;

		if (visited[tx] == -1) {
			visited[tx] = visited[x] + 1;
			q.push(tx);
		}
	}
	cout << "ANG" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(visited, -1, sizeof(visited));
	
	cin >> N >> T >> G;

	bfs(N);

	return 0;


}