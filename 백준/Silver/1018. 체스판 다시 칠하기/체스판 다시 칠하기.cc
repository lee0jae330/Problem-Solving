#include<iostream>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

char arr[51][51];

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 65;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int flag = 0;
			int now1 = 0;
			int now2 = 0;
			if (arr[i][j] == 'B')
				flag = 1;
			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if (x % 2) {
						if (y % 2) {
							if (arr[i + x][j + y] == 'W')
								now1++;
						}
						else { // 홀 짝
							if (arr[i + x][j + y] == 'B')
								now1++;
						}
					}
					else { //짝
						if (y % 2) { //짝 홀
							if (arr[i + x][j + y] == 'B')
								now1++;
						}
						else { //짝 짝
							if (arr[i + x][j + y] == 'W')
								now1++;
						}

					}
					if (x % 2) {
						if (y % 2) {
							if (arr[i + x][j + y] == 'B')
								now2++;
						}
						else { // 홀 짝
							if (arr[i + x][j + y] == 'W')
								now2++;
						}
					}
					else { //짝
						if (y % 2) { //짝 홀
							if (arr[i + x][j + y] == 'W')
								now2++;
						}
						else { //짝 짝
							if (arr[i + x][j + y] == 'B')
								now2++;
						}

					}
				}
			}
			int tmp;
			if (now1 <= now2)
				tmp = now1;
			else
				tmp = now2;
			if (tmp< cnt) {
				cnt = tmp;
				if (cnt == 0) {
					cout << cnt << '\n';
					return 0;
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}