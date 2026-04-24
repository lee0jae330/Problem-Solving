#include<bits/stdc++.h>

using namespace std;

int N, M, sol;
char arr[51][51];
int visited[51][51];
vector<pair<int,int>>v;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//가로 단서 시작점
			if (arr[i][j] == '.') { //비어있고
				if (j - 1 < 0 || arr[i][j - 1] == '#') { //왼쪽 칸 격자 벗어남 or 왼쪽 칸 막힘
					if (j + 2 < M) { // 오른쪽으로 2칸 이상 있을 때
						if (arr[i][j + 1] == '.' && arr[i][j + 2] == '.') {
							v.push_back({i+1,j+1});
							visited[i][j]=1;
						}
					}
				}
				if (i - 1 < 0 || arr[i - 1][j] == '#') {
					if(visited[i][j])
						continue;
					if (i + 2 < N) {
						if (arr[i + 1][j] == '.' && arr[i + 2][j] == '.') {
							v.push_back({i+1,j+1});
							visited[i][j]=1;
						}
					}
				}
			}
		}
	}

	cout << v.size() <<'\n';
	for (auto iter : v) {
		cout << iter.first <<' '<<iter.second <<'\n';
	}
	return 0;
}