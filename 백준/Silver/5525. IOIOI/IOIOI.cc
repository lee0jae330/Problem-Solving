#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int N, M;
	string str;
	cin >> N >> M >> str;
	int len = 2 * N + 1;
	int flag;
	int cnt = 0, ioi = 0, inc = 0;
	int result = 0;
	for (int i = 0; i < M; i++) {
		if (i == 0) {
			if (str[i] == 'I') {
				flag = 1;
				cnt=1;
			}
			else
				flag = -1;
		}
		else {
			if (flag == 1) {
				if (str[i] == 'O') {
					flag = -1;
					cnt++;
				}
				else {
					cnt = 1;
					ioi = 0;
				}
			}
			else {
				if (str[i] == 'I') {
					flag = 1;
					cnt++;
					if (cnt == 3) {
						ioi++;
						inc = 1;
					}
					cnt = 1;
				}
				else {
					cnt = 0;
					ioi = 0;
				}
			}
		}
		if (inc) {
			if (ioi >= N) {
				result++;
			}
			inc = 0;
		}
	}
	cout << result << '\n';
	return 0;
}