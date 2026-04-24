//*g5 & #bfs & %ko & !@$me

#include<bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int visited[1001][1001];
int sum[1001][1001];

int N, M, h, w, r, c;

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

queue<pair<int, int>>q;

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx <= 0 || ty <= 0 || tx > N || ty > M || visited[tx][ty]) {
				continue;
			}
			if (arr[x][y] <= arr[tx][ty]) {
				visited[tx][ty] = 1;
				q.push({ tx,ty });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	cin >> h >> w;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	
	int K;
	cin >> K;
	while (K--) {
		cin >> r >> c;
		q.push({ r,c });
		visited[r][c] = 1;
	}
	bfs();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visited[i][j]) {
				arr[i][j] = 0;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
		}
	}
	
	int cnt = 0;
    /*
    
    //(i,j) ~ (i+h-1,j+w-1)의 합 
    = (0,0)~(i+h-1,j+w-1) 
       - (0,0)~(i+h-1,j-1) 
       - (0,0) ~ (i-1,j+w-1) 
       + (0,0) ~ (i-1,j-1)
    */
    
	for (int i = 1; i <= N - h + 1; i++) { 
		for (int j = 1; j <= M - w + 1; j++) {
			if (sum[i + h - 1][j + w - 1] - sum[i + h - 1][j - 1] - sum[i - 1][j + w - 1] + sum[i - 1][j - 1] == 0) {
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}