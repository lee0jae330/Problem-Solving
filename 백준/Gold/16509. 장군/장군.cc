//*g5 & #bfs & %ko & !@$me


#include<bits/stdc++.h>

using namespace std;

int arr[11][11];
int visited[11][11];

int r1, r2, c1, c2;

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		if (x == r2 && y == c2) {
			cout << visited[x][y]-1 << '\n';
			return;
		}

		int tx = x - 1, ty = y;
		if (tx >= 0 && !arr[tx][ty]) {
			tx--;
			if (tx >= 0) {
				if (ty - 1 >= 0) {
					ty = y - 1;
					if (!arr[tx][ty]) {
						if (tx - 1 >= 0 && ty - 1 >= 0) {
							if (!visited[tx - 1][ty - 1]) {
								visited[tx - 1][ty - 1] = visited[x][y] + 1;
								q.push({ tx - 1,ty - 1 });
							}
						}
					}
				}
				if (ty + 1 < 9) {
					ty = y + 1;
					if (!arr[tx][ty]) {
						if (tx - 1 >= 0 && ty + 1 < 9) {
							if (!visited[tx - 1][ty + 1]) {
								visited[tx - 1][ty + 1] = visited[x][y] + 1;
								q.push({ tx - 1,ty + 1 });
							}
						}
					}
				}
			}
		}
		tx = x + 1, ty = y;
		if (tx < 10 && !arr[tx][ty]) {
			tx++;
			if (tx < 10) {
				if (ty - 1 >= 0) {
					ty = y - 1;
					if (!arr[tx][ty]) {
						if (tx + 1 < 10 && ty - 1 >= 0) {
							if (!visited[tx + 1][ty - 1]) {
								visited[tx + 1][ty - 1] = visited[x][y] + 1;
								q.push({ tx + 1,ty - 1 });
							}
						}
					}
				}
				if (ty + 1 < 9) {
					ty = y + 1;
					if (!arr[tx][ty]) {
						if (tx + 1 < 10 && ty + 1 < 9) {
							if (!visited[tx + 1][ty + 1]) {
								visited[tx + 1][ty + 1] = visited[x][y] + 1;
								q.push({ tx + 1,ty + 1 });
							}
						}
					}
				}
			}
		}
		tx = x, ty = y + 1;
		if (ty < 9 && !arr[tx][ty]) {
			ty++;
			if (ty < 9) {
				if (tx - 1 >= 0) {
					tx = x - 1;
					if (!arr[tx][ty]) {
						if (tx - 1 >= 0 && ty + 1 < 9) {
							if (!visited[tx - 1][ty + 1]) {
								visited[tx - 1][ty + 1] = visited[x][y] + 1;
								q.push({ tx - 1,ty + 1 });
							}
						}
					}
				}
				if (tx + 1 < 10) {
					tx = x + 1;
					if (!arr[tx][ty]) {
						if (tx + 1 < 10 && ty + 1 < 9) {
							if (!visited[tx + 1][ty + 1]) {
								visited[tx + 1][ty + 1] = visited[x][y] + 1;
								q.push({ tx + 1,ty + 1 });
							}
						}
					}
				}
			}
		}
		tx = x, ty = y - 1;
		if (ty >= 0 &&!arr[tx][ty]) {
			ty--;
			if (ty >= 0) {
				if (tx - 1 >= 0) {
					tx = x - 1;
					if (!arr[tx][ty]) {
						if (tx - 1 >= 0 && ty - 1 >= 0) {
							if (!visited[tx - 1][ty - 1]) {
								visited[tx - 1][ty - 1] = visited[x][y] + 1;
								q.push({ tx - 1,ty - 1 });
							}
						}
					}
				}
				if (tx + 1 < 10) {
					tx = x + 1;
					if (!arr[tx][ty]) {
						if (tx + 1 < 10 && ty - 1 >= 0) {
							if (!visited[tx + 1][ty - 1]) {
								visited[tx + 1][ty - 1] = visited[x][y] + 1;
								q.push({ tx + 1,ty - 1 });
							}
						}
					}
				}
			}
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	arr[r2][c2] = 1;
	bfs(r1, c1);
	return 0;
}