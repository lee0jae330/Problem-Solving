// *g5& #bfs & !@$me&% ko

#include<bits/stdc++.h>

using namespace std;

int N, S, P;

int visited[328001];

vector<int>v[328001];
set<int> sol;

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		x=q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i];
			if (visited[tx] != -1) {
				continue;
			}
			q.push(tx);
			visited[tx] = visited[x]+1;
		}
	}
}


void bfs1(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 0;
	while (!q.empty()) {
		x= q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i];
			if(visited[tx]!=-1)
				continue;
			visited[tx] = x;
			q.push(tx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S >> P;

	fill(visited,visited+328001,-1);

	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs(P);

	int min1 = -1, min2 = -1;

	for (int i = 1; i <= S; i++) {
		if (min1 == -1) {
			min1 = visited[i];
		}
		else {
			min1 = min(min1, visited[i]);
		}
	}
		
	vector<int> tmp;

	for (int i = 1; i <= S; i++) {
		if (min1 == visited[i]) {
			tmp.push_back(i);
			if(tmp.size()==2)
				break;
		}
	}

	if (tmp.size() < 2) {
		for (int i = 1; i <= S; i++) {
			if(visited[i]==min1)
				continue;
			if (min2 == -1) {
				min2 = visited[i];
			}
			else
				min2 = min(visited[i],min2);
		}

		for (int i = 1; i <= S; i++) {
			if (min2 == visited[i]) {
				tmp.push_back(i);
				break;
			}
		}
	}

	fill(visited,visited+328001,-1);
	bfs1(P);

	for (int i = 0; i < tmp.size(); i++) {
		int x = tmp[i];
		while (x) {
			sol.insert(x);
			x=visited[x];
		}
	}

	cout << N-sol.size() <<'\n';
	return 0;
}