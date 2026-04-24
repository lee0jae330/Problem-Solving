#include<bits/stdc++.h>

using namespace std;

int M, S;
vector<tuple<int, int, int>>sharkDir;
int sx, sy;
int isUsed[3];
int smell[4][4];

void makeSharkDir(int K) {
	if (K == 3) {
		sharkDir.push_back({ isUsed[0],isUsed[1],isUsed[2] });
		return;
	}
	for (int i = 0; i < 4; i++) {
		isUsed[K] = i;
		makeSharkDir(K + 1);
	}
}

class fish {
	public:
		int x, y;
		int dir;
		int isOut = 0;
	public:
		fish() {

		}
		fish(int x, int y, int dir) {
			this->x = x;
			this->y = y;
			this->dir = dir;
		}
};

vector<fish>f;

void printFish() {
	cout << "---printFish---" << '\n';
	for (int i = 0; i < f.size(); i++) {
		cout << i << ' ' << f[i].x << ' ' << f[i].y << ' ' << f[i].dir << '\n';
	}
	cout << "---------------" << '\n';
}

vector<fish>cp;

void copyFish() {
	cp.clear();
	for (int i = 0; i < f.size(); i++) {
		if (!f[i].isOut)
			cp.push_back(f[i]);
	}
	/*cout << "------copy------\n";
	for (int i = 0; i < cp.size(); i++) {
		cout << i << ' ' << cp[i].x << ' ' << cp[i].y << ' ' << cp[i].dir << '\n';
	}
	cout << "---------------" << '\n';
	*/
}

void pasteFish() {
	for (int i = 0; i < cp.size(); i++)
		f.push_back(cp[i]);
	cp.clear();

	/*cout << "------paste------\n";
	for (int i = 0; i < f.size(); i++) {
		cout << i << ' ' << f[i].x << ' ' << f[i].y << ' ' << f[i].dir << '\n';
	}
	cout << "---------------" << '\n';*/
}

void fishMove() {
	int xx[8] = { 0,-1,-1,-1,0,1,1,1 };
	int yy[8] = { -1,-1,0,1,1,1,0,-1 };
	int fishSize = f.size();
	for (int i = 0; i < fishSize; i++) {
		fish &tmp = f[i];
		int d = tmp.dir;
		int x = tmp.x, y = tmp.y;
		do {
			int tx = x + xx[d], ty = y + yy[d];
			if ((tx >= 0 && ty >= 0 && tx < 4 && ty < 4) && !smell[tx][ty] && (sx != tx || sy != ty)) {
				//물고기 이동 가능한 조건일 때
				tmp.x = tx;
				tmp.y = ty;
				tmp.dir = d;
				break;
			}
			else {
				d--;
				if (d == -1)
					d = 7;
			}
		} while (d != tmp.dir);
	}
	//printFish();
}

void sharkMove() {
	int numOfFish = -1;
	int tmpSmell[4][4] = { 0, };
	int xx[4] = { -1,0,1,0 };
	int yy[4] = { 0,-1,0,1 };
	int tsx = sx, tsy = sy;
	vector<fish>result; //상어 이동을 마친뒤 물고기 배열
	
	for (int i = 0; i < 64; i++) {
		vector<fish>alive;
		vector<fish>tmpfish = f;
		int sz = tmpfish.size();
		int tmpSx=sx, tmpSy=sy;
		int order1, order2, order3;
		tie(order1,order2,order3) = sharkDir[i];
		int curFish = 0;
		int curSmell[4][4] = { 0, };
		//현재 이동방법이 가능한 방법인지 검사
		int flag = 0;
		for (auto d : { order1,order2,order3 }) {
				tmpSx += xx[d], tmpSy += yy[d];
				if (tmpSx < 0 || tmpSy < 0 || tmpSx >= 4 || tmpSy >= 4) {
					flag = 1;
					break;
				}
		}
		if (flag) //이동불가한 방법일시 스킵
			continue;
		int x1, x2, x3, y1, y2, y3;
		x1 = sx + xx[order1], y1 = sy + yy[order1];
		x2 = x1 + xx[order2], y2 = y1 + yy[order2];
		x3 = x2 + xx[order3], y3 = y2 + yy[order3];
		for (int i = 0; i < sz; i++) {
			fish &tf = tmpfish[i];
			if (tf.isOut)
				continue;
			if ((tf.x == x1 && tf.y == y1) || (tf.x == x2 && tf.y == y2) || tf.x == x3 && tf.y == y3) {
				curFish++;
				curSmell[tf.x][tf.y] = 2;
				tf.isOut = 1;
			}
			else {
				//생존한 물고기
				alive.push_back(tf);
			}
		}
		if (numOfFish < curFish){
			//만약 이전보다 많은 물고기를 제외시켰을떼
			//마릿수 최신화
			//물고기 상태배열 최신화
			//냄새 배열 최신화
			//상어 위치 최신화
			numOfFish = curFish;
			result = alive;
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++)
					tmpSmell[r][c] = curSmell[r][c];
			}
			tsx = tmpSx;
			tsy = tmpSy;
		}
	}
	sx = tsx, sy = tsy;
	f = result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (smell[i][j])
				smell[i][j]--;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (tmpSmell[i][j])
				smell[i][j]=2;
		}
	}
	/*cout << "numOfFish : " << numOfFish << '\n';
	cout << sx << ' ' << sy << '\n';
	printFish();
	cout << '\n';
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << smell[i][j] << ' ';
		cout << '\n';
	}*/
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	makeSharkDir(0); //상어의 이동방법 만들기 64개
	
	cin >> M >> S;
	while (M--) {
		int fx, fy, d;
		cin >> fx >> fy >> d;
		f.push_back(fish(fx-1, fy-1, d-1));
	}
	cin >> sx >> sy;
	sx--; sy--;
	while (S--) {
		//1.물고기 복사
		copyFish();
		//2.물고기 이동
		fishMove();
		//3.상어 이동
		sharkMove();
		//4.복제 완료
		pasteFish();
	}
	int cnt = 0;
	for (int i = 0; i < f.size(); i++) {
		if (!f[i].isOut)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;

}