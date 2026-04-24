#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[21][21];
int visited[21][21];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

int standardx, standardy;
int mx_num=-1, mx_rainbow=0;
int score = 0;

pair<int,int> bfs(int x, int y) {
	queue<tuple<int, int, int>>q; //좌표, 색깔
	q.push({ x,y,arr[x][y] });
	int cnt = 1, rainbow = 0;
	visited[x][y] = 1;
	int color;
	while (!q.empty()) {
		tie(x, y, color) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= N || visited[tx][ty])
				continue;
			if (arr[tx][ty] == 9)
				continue;
			if (arr[tx][ty] == color || !arr[tx][ty]) {
				int r = 0;
				if (!arr[tx][ty]) {
					r = 1;
					rainbow++;
				}
				cnt++;
				visited[tx][ty] = 1;
				q.push({ tx,ty,color});

			}
		}
	}
	return { cnt, rainbow }; //그룹 개수, 무지개 개수
}

void fall() {
	for (int c = 0; c < N; c++) {
		int cnt = 0;
		for (int r = N - 1; r >= 0; r--) {
			if (r == N - 1)
				continue;
			if (arr[r][c] != -1 && arr[r][c] != 9) {
				for (int i = r + 1; i < N; i++) {
					if (arr[i][c] == 9) {
						if (i == N - 1) {
							swap(arr[i][c], arr[r][c]);
							break;
						}
						else
							continue;
					}
					else {
						swap(arr[i - 1][c], arr[r][c]);
						break;
					}
				}
			}
		}
	}
}

void spin() {
	int tmp[21][21];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[N - j - 1][i] = tmp[i][j];
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	while (1) {
		//크기가 가장 큰 블록 그룹을 찾는다.
		memset(visited, 0, sizeof(visited));
		mx_num = -1, mx_rainbow = 0;
		int flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				pair<int, int>tmp;
				if (arr[i][j] > 0 &&arr[i][j]!=9&& !visited[i][j]) {
					tmp = bfs(i, j);
					auto [cnt, rain] = tmp;
					if (cnt >= 2)
						flag = 1;
					if (mx_num < cnt) { //그룹 개수가 현재까지의 최대 개수보다 크면 갱신
						mx_num = cnt;
						mx_rainbow = rain;
						standardx = i, standardy = j;
					}
					else if (mx_num == cnt) { //그룹 개수와 현재까지의 최대 개수가 같으면
						if (mx_rainbow < rain) { //무지개 블록 수로 비교
							mx_rainbow = rain;
							standardx = i, standardy = j;
						}
						else if (mx_rainbow == rain) { //만약 둘다 같으면, 반복문이 돌면 돌수록 행,열이 커지기 때문에 갱신
							standardx = i, standardy = j;
						}
					}
					for (int r = 0; r < N; r++) {
						for (int c = 0; c < N; c++) {
							if (!arr[r][c])
								visited[r][c] = 0;
						}
					}
				}
			}
		}
		if (!flag)
			break;
		memset(visited, 0, sizeof(visited));
		bfs(standardx, standardy);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				if (visited[i][j])
					arr[i][j] = 9;
		}
		score += (mx_num * mx_num);
		fall();
		spin();
		fall();
	}
	cout << score << '\n';
	return 0;
}