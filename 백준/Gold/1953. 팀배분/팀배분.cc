#include<bits/stdc++.h>

using namespace std;

vector<int> v[101];

int visited[101];

int N;

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 0;

	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i];
			if (visited[tx] == -1) {
				visited[tx] = visited[x] ? 0 : 1;
				q.push(tx);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}

	memset(visited, -1, sizeof(visited));

	for (int i = 1; i <= N; i++) {
		if (visited[i] == -1) {
			bfs(i);
		}
	}

	vector<int>tmp; 
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			tmp.push_back(i);
		}
	}

	cout << tmp.size() << '\n';
	for (int n : tmp) {
		cout << n << ' ';
	}
	cout << '\n';
	tmp.clear();
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) {
			tmp.push_back(i);
		}
	}
	cout << tmp.size() << '\n';
	for (int n : tmp) {
		cout << n << ' ';
	}
	return 0;
}