#include<bits/stdc++.h>

using namespace std;

int N, M, D;
int arr[16][16]; //빈칸: 0, 적:1, 궁수:2
int cp[16][16];
int visited[16][16];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

vector<pair<int, int>>acher;

int sol = -1;


void bfs(pair<int, int > p) {
	auto [x, y] = p;
	visited[x][y] = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty<0 || tx>N || ty >= M || visited[tx][ty])
				continue;
			visited[tx][ty] = visited[x][y]+1;
			q.push({ tx,ty });
		}
	}
}


void game() {
	int cnt = 0;
	int isOut[16][16] = { 0, };
	while (1) {
		int flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j])
					flag = 1;
			}
		}
		if (!flag)
			break;
		memset(isOut, 0, sizeof(isOut));
		for (int i = 0; i < acher.size(); i++) {
			memset(visited, 0, sizeof(visited));
			bfs(acher[i]);
			int dist = 123456789;
			int ex, ey;
			int f = 0;
			for (int c = 0; c < M; c++) {
				for (int r = N - 1; r >= 0; r--) {
					if (arr[r][c] && visited[r][c] - 1 <= D && dist > visited[r][c] - 1) {
						f = 1;
						ex = r, ey = c;
						dist = visited[r][c] - 1;
					}
				}
			}
			if (f)
				isOut[ex][ey] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (isOut[i][j]) {
					arr[i][j] = 0;
					cnt++;
				}
			}
		}
		//적이동
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (i == N - 1) {
					if (arr[i][j])
						arr[i][j] = 0;
				}
				else {
					swap(arr[i][j], arr[i + 1][j]);
				}
			}
		}
	}
	sol = max(sol, cnt);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			cp[i][j] = arr[i][j];
		}
			
	}
	vector<int>comb;
	for (int i = 0; i < 3; i++)
		comb.push_back(0);
	for (int i = 0; i < M - 3; i++)
		comb.push_back(1);

	do {
		//필드 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				arr[i][j] = cp[i][j];
		}
		//궁수 위치 선정
		acher.clear();
		for (int i = 0; i < M; i++) {
			if (!comb[i]) {
				acher.push_back({ N,i });
			}
		}
		game();
	} while (next_permutation(comb.begin(), comb.end()));
	cout << sol << '\n';
	return 0;
}