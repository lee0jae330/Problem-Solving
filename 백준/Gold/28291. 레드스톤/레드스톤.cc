#include<bits/stdc++.h>

using namespace std;

int W, H;
int arr[51][51];
int visited[51][51];

int lamp[51][51];
int isOn[51][51];

int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};

void bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[x][y] =16;
	while (!q.empty()) {
		tie(x,y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx =x+xx[i],ty=y+yy[i];
			if (tx < 0 || ty < 0 || tx >= H || ty >= W||visited[tx][ty]) {
				continue;
			}
			if (visited[x][y] == 1)
				continue;
			if (arr[tx][ty] == 3) {
				visited[tx][ty]= visited[x][y]-1;
			}
			if (arr[tx][ty] == 1) {
				visited[tx][ty] = visited[x][y] - 1;
				q.push({ tx,ty });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> W >> H; //가로, 세로

	int N;
	cin >>  N;
	while (N--) {
		string str;
		int x, y; //가로, 세로
		cin >> str >> x >> y;
		//가루:1, 블록:2, 램프:3
		if (str == "redstone_block") {
			arr[y][x] = 2;
		}
		else if (str == "redstone_dust") {
			arr[y][x] = 1;
		}
		else {
			arr[y][x] =3;
			lamp[y][x]=1;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] == 2) {
				memset(visited,0,sizeof(visited));
				bfs(i,j);

				for (int r = 0; r < H; r++) {
					for (int c = 0; c < W; c++) {
						if (visited[r][c] && lamp[r][c]) {
							isOn[r][c] =1;
						}
					}
				}
			}
		}
	}

	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			if (isOn[r][c] != lamp[r][c]) {
				cout << "failed" <<'\n';
				return 0;
			}
		}
	}
	cout << "success" <<'\n';
	return 0;
}