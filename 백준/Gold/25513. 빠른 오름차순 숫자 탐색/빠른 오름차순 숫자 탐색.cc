#include<bits/stdc++.h>

using namespace std;

int arr[5][5];
int visited[5][5];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

int r, c, sol=0;


void bfs(int x, int y, int num) {
	int cnt = 0;
	queue<tuple<int,int,int>>q;
	q.push({ x,y,cnt });
	visited[x][y] = 1;
	while (!q.empty()) {
		tie(x, y, cnt) = q.front();
		if (arr[x][y] == num) {
			r=x, c=y;
			sol += cnt;
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5 || visited[tx][ty] || arr[tx][ty] == -1) {
				continue;
			}
			visited[tx][ty]=1;
			q.push({tx,ty,cnt+1});

		}
	}
	sol = -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> r >> c;
	
	for (int i = 1; i <= 6; i++) {
		memset(visited,0,sizeof(visited));
		bfs(r,c,i);
		if (sol == -1) {
			cout << -1<< '\n';
			return 0;
		}
	}
	cout << sol <<'\n';
	return 0;
}