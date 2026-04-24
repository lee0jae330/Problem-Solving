#include<iostream>
#include<queue>
#include<utility>

using namespace std;

const int MAX = 101;

char arr[MAX][MAX];

int xx[8] = { 1,1,1,0,-1,-1,-1,0 };
int yy[8] = { -1,0,1,1,1,0,-1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int sol = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'M') {
				for (int k = 0; k < 8; k++) {
					string str = "M";
					for (int l = 1; l <= 4; l++) {
						int tx = i + l * xx[k];
						int ty = j + l * yy[k];

						if (tx < 0 || ty < 0 || tx >= N || ty >= N) {
							break;
						}

						str.push_back(arr[tx][ty]);
					}
					if (str == "MOBIS") {
						sol++;
					}
				}

			}
		}
	}
	cout << sol << '\n';
	return 0;
}