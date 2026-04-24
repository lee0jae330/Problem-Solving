#include<bits/stdc++.h>

using namespace std;

vector<int> v[100001];

int visited[100001];

bool compare(const int& a, const int& b) {
	return a>b;
}


void bfs(int x) {
	queue<int>q;
	q.push(x);
	int order=1;
	visited[x]=order++;
	while (!q.empty()) {
		x= q.front();
		q.pop();
		for(int i=0;i<v[x].size();i++) {
			if(visited[v[x][i]])
				continue;
			visited[v[x][i]] = order++;
			q.push(v[x][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M,R;
	cin >> N >> M >>R;
	for (int i = 0; i < M; i++) {
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(),v[i].end(),compare);
	}

	bfs(R);

	for (int i = 1; i <= N; i++) {
		cout << visited[i] <<'\n';
	}
	return 0;
}