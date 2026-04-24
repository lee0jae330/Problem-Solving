#include<bits/stdc++.h>

using namespace std;

char arr[2][100001];
int visited[2][100001];

int N,K;

int flag=0;

void bfs(int x, int y, int t) {
	queue<tuple<int,int,int>>q;
	q.push({x,y,t});
	visited[x][y]=1;
	while (!q.empty()) {
		tie(x,y,t) = q.front();
		q.pop();
		int tx = x, ty= y+1;
		if (ty > N) {
			cout << 1 <<'\n';
			return;
		}
		if (arr[tx][ty] == '1' && !visited[tx][ty]) {
			if (ty == N) {
				cout << 1 <<'\n';
				return;
			}
			visited[tx][ty]=1;
			q.push({tx,ty,t+1});
		}

		tx = (x==0) ? 1 : 0, ty = y + K;
		if (ty > N) {
			cout << 1 <<'\n';
			return;
		}
		if (arr[tx][ty] == '1' && !visited[tx][ty]) {
			if (ty == N) {
				cout << 1 << '\n';
				return;
			}
			visited[tx][ty] = 1;
			q.push({ tx,ty,t + 1 });
		}
		tx = x, ty = y-1;
		if (t + 1 < ty && arr[tx][ty] == '1' && !visited[tx][ty]) {
			visited[tx][ty]=1;
			q.push({tx,ty,t+1});
		}
	}
	cout << 0<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	bfs(0,1,0);
	return 0;
}