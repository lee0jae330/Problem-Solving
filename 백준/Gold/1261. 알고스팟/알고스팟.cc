#include<bits/stdc++.h>

using namespace std;

int N, M;
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

char arr[101][101];
int visited[101][101];

void bfs(int x, int y, int cnt) {
	deque<tuple<int,int,int>>dq;
	dq.push_back({x,y,cnt});
	visited[x][y] = 1;
	while (!dq.empty()) {
		tie(x, y, cnt) = dq.front();
		dq.pop_front();
		if (x == N - 1 && y == M - 1) {
			cout << cnt <<'\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nxt = cnt;
			int tx = x + xx[i], ty = y + yy[i];
			if(tx<0||ty<0||tx>=N||ty>=M)
				continue;
			if(visited[tx][ty])
				continue;
			visited[tx][ty]=1;
			if (arr[tx][ty] == '1') {
				dq.push_back({tx,ty,cnt+1});
			}
			else {
				dq.push_front({tx,ty,cnt});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	bfs(0,0,0);
	return 0;
	
}