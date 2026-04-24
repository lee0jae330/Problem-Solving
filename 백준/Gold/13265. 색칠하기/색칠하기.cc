// *g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int color[1001];

vector<int>v[1001];

int flag = 0;

void bfs(int x, int col) {
	queue<pair<int, int>>q;
	q.push({ x,col });
	color[x] = col;
	while (!q.empty()) {
		tie(x, col) = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i];
			if (color[tx] == -1) {
				if (!col) {
					color[tx] = 1;
				}
				else {
					color[tx] = 0;
				}
				q.push({ tx,color[tx] });
			}
			else {
				if (color[tx] == col) {
					flag = 1;
					return;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		flag = 0;
		memset(color, -1, sizeof(color));
		for (int i = 0; i < 1001; i++) {
			v[i].clear();
		}
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}

		for (int i = 1; i <= N; i++) {
			if (color[i] == -1) {
				bfs(i, 0);
			}
		}
		if (flag) {
			cout << "impossible" << '\n';
		}
		else {
			cout << "possible" << '\n';
		}
	}
	return 0;
}