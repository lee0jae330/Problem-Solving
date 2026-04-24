#include<bits/stdc++.h>

using namespace std;

int N,M;

int arr[5001][5001];

int xx[4] = {0,1,0,-1};
int yy[4] = {1,0,-1,0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int x =0, y=0;

	int dir = 0;
	int cnt = 0;

	while (1) {
		//cout << x <<' '<<y <<'\n';
		arr[x][y] =1;
		int tx = x+xx[dir], ty = y+yy[dir];
		if (tx < 0 || tx >= M || ty < 0 || ty >= N||arr[tx][ty]) {
			if (cnt == 1) {
				cout << y << ' ' << x <<'\n';
				return 0;
			}
			if(dir==3)
				dir=0;
			else
				dir++;
			cnt++;
			continue;
		}
		arr[tx][ty] =1;
		cnt = 0;
		x = tx, y= ty;
	}
	cout << y <<' '<<x <<'\n';
	return 0;
}