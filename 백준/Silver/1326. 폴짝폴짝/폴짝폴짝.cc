#include<bits/stdc++.h>

using namespace std;

int N;
int arr[10001];
int visited[10001];

int a, b;

void bfs(int x) {
	int cnt =0;
	queue<pair<int,int>>q;
	q.push({x,cnt});
	visited[x]=1;
	while (!q.empty()) {
		tie(x,cnt) = q.front();
		q.pop();
		if (x == b) {
			cout << cnt <<'\n';
			return;
		}
		
		for (int i = 0; x+arr[x] * i <= N; i++) {
			int tx = arr[x] *i;
			if (!visited[x + tx]) {
				q.push({x+tx,cnt+1});
				visited[x+tx] =1;
			}
		}
		for (int i = 0;; i++) {
			int tx = arr[x]*i;
			if(x-tx<=0)
				break;
			if (!visited[x - tx]) {
				q.push({x-tx,cnt+1});
				visited[x-tx]=1;
			}
		}
	}
	cout << -1 <<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	 cin >> N;
	 for (int i = 1; i <= N; i++) {
		 cin >> arr[i];
	 }
	 cin >> a >> b;
	 bfs(a);
	 return 0;
}