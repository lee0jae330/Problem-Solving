#include<bits/stdc++.h>

using namespace std;

int R, C;

char arr[1001][1001];
int visited[1001][1001];
int field[1001][1001];
char sol[1001][1001];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

void bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[x][y]=1;
	while (!q.empty()) {
		tie(x,y) = q.front();
		sol[x][y] ='.';
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx=x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= R || ty >= C||visited[tx][ty]) {
				continue;
			}
			if (arr[tx][ty] == arr[x][y]) {
				visited[tx][ty]=1;
				q.push({tx,ty});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	x--, y--;
	string cmd;
	cin >> cmd;
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i] == 'W') {
			field[x][y] = 1;
		}
		else if (cmd[i] == 'L') {
			y--;
		}
		else if (cmd[i] == 'R') {
			y++;
		}
		else if (cmd[i] == 'U') {
			x--;
		}
		else {
			x++;
		}
	}

	for (int i = 0; i < R; i++) {
		fill(sol[i], sol[i] + C, '#');
	}

	sol[x][y] ='.';
	for (int i = 0; i < 4; i++) {
		int tx = x+xx[i],ty=y+yy[i];
		if(tx<0||ty<0||tx>=R||ty>=C)
			continue;
		sol[tx][ty] = '.';
	}
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j] && field[i][j]) {
				bfs(i,j);
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << sol[i][j];
		}
		cout <<'\n';
	}
	return 0;
}