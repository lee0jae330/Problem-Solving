//*g5 & #bfs & %ko & !@$me


#include<bits/stdc++.h>

using namespace std;

int N, M;
string L, K;

int visited[1<<11];

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x == M) {
			cout << visited[x] << '\n';
			return;
		}
		vector<int> v;
		int tmp = x;
		while (tmp) {
			int mod = tmp % 2;
			v.push_back(mod);
			tmp /= 2;
		}
		if (!v.empty()) {
			for (int i = 0; i < (v.size() - 1); i++) {
				int tx;
				if (v[i]) {
					tx = x - pow(2, i);
				}
				else {
					tx = x + pow(2, i);
				}
				if (tx >= 0 && (1 << 10) > tx) {
					if (visited[tx] == -1) {
						visited[tx] = visited[x] + 1;
						q.push(tx);
					}
				}
			}
		}
		
		if (x + 1 < (1 << 10)) {
			if (visited[x + 1] == -1) {
				visited[x + 1] = visited[x]+1;
				q.push(x+1);
			}
		}
		if (x - 1 >= 0) {
			if (visited[x - 1] == -1) {
				visited[x - 1] = visited[x] + 1;
				q.push(x - 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(visited, -1, sizeof(visited));

	cin >> L >> K;
	reverse(L.begin(), L.end());
	reverse(K.begin(), K.end());
	N += (L[0] - '0');
	for (int i = 1; i < L.size(); i++) {
		int tmp = (1 << i);
		N += (tmp * (L[i] - '0'));
	}
	M += (K[0] - '0');
	for (int i = 1; i < K.size(); i++) {
		int tmp = (1 << i);
		M += (tmp * (K[i] - '0'));
	}


	bfs(N);
	return 0;
}