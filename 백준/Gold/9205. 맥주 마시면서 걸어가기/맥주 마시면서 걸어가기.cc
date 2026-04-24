#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>>arr;

vector<int>v[105];

int visited[105];

int sx,sy, ex, ey;

void bfs() {
	queue<int>q;
	q.push(0);
	visited[0] =1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx= v[x][i];
			if(visited[tx])
				continue;
			visited[tx]=1;
			q.push(tx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		memset(visited,0,sizeof(visited));
		arr.clear();
		for (int i = 0; i < 105; i++) {
			v[i].clear();
		}
		int N;
		cin >> N;
		cin >> sx >> sy;
		arr.push_back({sx,sy});
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			arr.push_back({x,y});
		}
		cin >> ex >> ey;
		arr.push_back({ex,ey});
		for (int i = 0; i < arr.size(); i++) {
			for(int j=0;j<arr.size();j++) {
				if(i==j)	
					continue;
				if(abs(arr[i].first-arr[j].first)+abs(arr[i].second-arr[j].second)<=1000)
					v[i].push_back(j);
			}
		}

		bfs();

		if (visited[arr.size()-1]) {
			cout << "happy" <<'\n';
		}
		else {
			cout << "sad" <<'\n';
		}

	}
}