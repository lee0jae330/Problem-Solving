//#bfs & *g4 & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int visited[1001][1001];
vector<int>v[1001];
set<int>sol;
int N, M, X, Y;

void bfs(int x, int cnt) {
	visited[x][cnt] = 0;
	queue<pair<int,int>>q;
	q.push({x,cnt});

	while (!q.empty()) {
		tie(x, cnt) = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i];
			if (visited[tx][cnt + 1]) {
				continue;
			}
			else {
				visited[tx][cnt + 1] = 1;
				if (cnt + 1 == Y) {
					sol.insert(tx);
				}
				else {
					q.push({ tx,cnt + 1 });
				}
			}

		}
	}
	
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> X >> Y;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(X,0);

	if (sol.empty()) {
		cout << -1 << '\n';
	}
	else {
		for (int num : sol) {
			cout << num << ' ';
		}
	}
	return 0;
}