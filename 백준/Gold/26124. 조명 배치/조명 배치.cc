// *g5& #bfs & !@$me&% ko

#include<bits/stdc++.h>

using namespace std;

int H,W;

int arr[1001][1001];

int visited[1001][1001];

queue<pair<int,int>>q;

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

void bfs() {
	while (!q.empty()) {
		auto[x,y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx =x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= H || ty >= W||visited[x][y]==1||arr[tx][ty]==-1) {
				continue;
			}
			if (!visited[tx][ty]) { //방문 안한 곳
				visited[tx][ty] = visited[x][y]-1;
				q.push({tx,ty});
			}
			else {
				if (visited[tx][ty] < visited[x][y] - 1) {
					visited[tx][ty] = visited[x][y] -1;
					q.push({tx,ty});
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> H >> W;
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt =0;

	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			if (!arr[x][y] || arr[x][y] == -1) {
				if (arr[x][y] == -1) {
					visited[x][y] = -1;
				}
				continue;
			}
				
			int flag =0;
			for (int i = 0; i < 4; i++) {
				int tx = x+xx[i],ty=y+yy[i];
				if (tx<0 || ty<0 || tx>=H || ty>=W) {
					continue;
				}
				if (arr[tx][ty] > arr[x][y]) {
					flag=1;
				}
			}
			if (!flag) {
				cnt++;
				q.push({x,y});
				visited[x][y] = arr[x][y];
			}
		}
	}

	bfs();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] != visited[i][j]) {
				cout << -1<<'\n';
				return 0;
			}
		}
	}
	cout << cnt<<'\n';
	return 0;
}