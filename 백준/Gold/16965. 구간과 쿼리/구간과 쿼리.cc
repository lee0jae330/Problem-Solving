//* g5& #bfs & !@$me&% ko

#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

int visited[101];

void bfs(int n) {
	queue<int>q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		n = q.front();
		q.pop();
		auto [x1, y1] = v[n];
		for (int i = 0; i < v.size(); i++) {
			if (!visited[i]) {
				auto [x2, y2] = v[i];
				if ((x2 < x1 && x1 < y2) || (x2 < y1 && y1 < y2)) {
					q.push(i);
					visited[i] = 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	while (N--) {
		int num, x, y;
		cin >> num >> x >> y;
		if (num == 1) {
			v.push_back({ x,y });
		}
		else {
			memset(visited, 0, sizeof(visited));
			bfs(x-1);
			if(visited[y-1])
				cout << 1 <<'\n';
			else
				cout << 0<<'\n';
		}
	}
	return 0;
}