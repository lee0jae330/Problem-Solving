//*g5 & #bfs & %ko & !@$me

#include<bits/stdc++.h>

using namespace std;

vector<int> v[51];
int visited[51];

vector<pair<int, int>>sol;

int N;

int bfs(int x) {
	int dist = -1;
	queue<int>q;
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i];
			if (visited[tx] != -1)
				continue;
			visited[tx] = visited[x] + 1;
			dist = max(dist, visited[tx]);
			q.push(tx);
		}
	}
	return dist;
}


bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && a == b) {
			break;
		}
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		fill(visited, visited + 51, -1);
		int dist = bfs(i);
		sol.push_back({ i,dist });
	}

	sort(sol.begin(), sol.end(), comp);

	int num = sol[0].second;

	vector<int> president;

	for (int i = 0; i < sol.size(); i++) {
		if (num == sol[i].second) {
			president.push_back(sol[i].first);
		}
		else {
			break;
		}
	}

	cout << num << ' ' << president.size() << '\n';
	for (int n : president)
		cout << n << ' ';

	return 0;
}