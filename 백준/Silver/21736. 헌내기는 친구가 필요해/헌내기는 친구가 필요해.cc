#include<bits/stdc++.h>

using namespace std;

int N, M;

char arr[601][601];
int visited[601][601];


int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

void bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push({x,y});
	visited[x][y] = 1;
	int cnt =0;

	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x+xx[i],ty=y+yy[i];
			if(tx<0||ty<0||tx>=N||ty>=M||visited[tx][ty]||arr[tx][ty]=='X')
				continue;
			if(arr[tx][ty]=='P')
				cnt++;
			q.push({tx,ty});
			visited[tx][ty]=1;
		}
	}
	if(cnt)
		cout << cnt <<'\n';
	else
		cout<< "TT" <<'\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int x=1, y=1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'I') {
				bfs(i,j);
				return 0;
			}
		}
	}

	return 0;

}