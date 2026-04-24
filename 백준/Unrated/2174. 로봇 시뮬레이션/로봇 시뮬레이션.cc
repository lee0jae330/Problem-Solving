#include<bits/stdc++.h>

using namespace std;

int A, B, N, M;

int arr[101][101];

int yy[4] = { 0,1,0,-1 };
int xx[4] = { 1,0,-1,0 };

class robot {
public:
	int x, y;
	int dir;
public:
	robot(int x, int y, char dir) {
		this->x = x - 1;
		this->y = B - y;
		switch (dir) {
			case 'E':
				this->dir = 0;
				break;
			case 'S':
				this->dir = 1;
				break;
			case 'W':
				this->dir = 2;
				break;
			default:
				this->dir = 3;
		}
		
	}
};

vector<robot>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i <= 100; i++) {
		fill(arr[i], arr[i] + 101, -1);
	}

	cin >> A >> B >> N >> M;

	int idx = 0;
	for (int i = 0; i < N; i++) {
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		v.push_back(robot(x, y, dir));
		arr[B - y][x - 1] = idx++;
	}

	while (M--) {
		int num, repeat;
		char cmd;
		cin >> num >> cmd >> repeat;
		if (cmd == 'L') {
			for (int i = 0; i < repeat; i++) {
				if (v[num - 1].dir == 0) {
					v[num-1].dir = 3;
				}
				else {
					v[num-1].dir--;
				}
			}
		}
		else if (cmd == 'R') {
			for (int i = 0; i < repeat; i++) {
				if (v[num - 1].dir == 3) {
					v[num - 1].dir = 0;
				}
				else {
					v[num - 1].dir++;
				}
			}
		}
		else {
			int dir = v[num-1].dir;
			while (repeat--) {
				int tx = v[num-1].x + xx[dir];
				int ty = v[num-1].y + yy[dir];
				if (ty < 0 || ty >= B || tx < 0 || tx >= A) {
					cout << "Robot " << num << " crashes into the wall"<<'\n';
					return 0;
				}
				else if (arr[ty][tx] != -1) {
					cout << "Robot " << num << " crashes into robot " << arr[ty][tx]+1 <<'\n';
					return 0;
				}
				else {
					swap(arr[ty][tx],arr[v[num-1].y][v[num-1].x]);
					v[num-1].x = tx;
					v[num-1].y = ty;
				}
			}
		}
	}
	cout <<"OK" <<'\n';
	return 0;
}