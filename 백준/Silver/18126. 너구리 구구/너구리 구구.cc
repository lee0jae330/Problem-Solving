#include<bits/stdc++.h>

using namespace std;

int N;
int visited[5001];
vector<pair<int,long long>>v[5001];
long long mx =0;

void bfs(int x) {
	long long dist =0;
	queue<pair<int,long long>>q;
	q.push({x,dist});
	visited[x]=0;
	while (!q.empty()) {
		tie(x,dist) = q.front();
		q.pop();
		mx = max(mx, dist);
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i].first;
			long long cost = v[x][i].second;
			if (visited[tx] == -1) {
				visited[tx] = visited[x]+1;
				q.push({tx,dist+cost});
			}
		}
	}
	cout << mx <<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		long long c;
		cin >> a>> b>> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	memset(visited,-1,sizeof(visited));
	bfs(1);
	return 0;
}