#include<bits/stdc++.h>

using namespace std;

char arr[11][11];
int visited[101][11][11];
vector<pair<int, int>>cord;

int N, M;

int xx[8] = { -2,-1,1,2,2,1,-1,-2 };
int yy[8] = { 1,2,2,1,-1,-2,-2,-1 };

void bfs(int x, int y, int num) {
	int max_move_cnt = arr[x][y] - '0';
	int tmpx = x, tmpy=y;
	visited[num][x][y] = 0;
	int cnt = 0;
	int flag=1;

	if (max_move_cnt == 1) {
		queue<pair<int,int>>q;
		q.push({x,y});
		while (!q.empty()) {
			tie(x,y) = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				int tx = x + xx[i], ty = y + yy[i];
				if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[num][tx][ty] != -1) {
					continue;
				}
				visited[num][tx][ty] = visited[num][x][y] +1;
				q.push({tx,ty});
			}
		}
		return;
	}

	queue<tuple<int, int, int, int>>q;
	q.push({ x,y,cnt, flag});
	while (!q.empty()) {
		tie(x, y, cnt, flag) = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int tx = x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M||visited[num][tx][ty]!=-1) {
				continue;
			}
			if (cnt + 1 > max_move_cnt) {
				visited[num][tx][ty] = visited[num][x][y] +1;
				q.push({tx,ty,0,0});
			}
			else {
				visited[num][tx][ty] = visited[num][x][y]+flag;
				q.push({tx,ty,cnt+1,0});
			}
		}
	}
	visited[num][tmpx][tmpy] =0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != '.') {
				cord.push_back({ i,j });
			}
		}
	}

	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < cord.size(); i++) {
		auto [x, y] = cord[i];
		bfs(x, y, i);
	}

	/*
	cout << '\n';
	for (int i = 0; i < cord.size(); i++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				cout << visited[i][x][y] <<' ';
			}
			cout << '\n';

		}
		cout << '\n';
	}
	*/

	int sol =1234567890;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int sum =0;
			int flag=0;
			for (int x = 0; x < cord.size(); x++) {
				if (visited[x][i][j] == -1) {
					flag=1;
					break;
				}
				sum += visited[x][i][j];
			}
			if(flag)
				continue;
			sol = min(sol, sum);
		}
	}
	if (sol == 1234567890) {
		cout << -1 <<'\n';
	}
	
	else {
		cout << sol <<'\n';
	}
	return 0;
}