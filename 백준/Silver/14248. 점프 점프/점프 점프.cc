#include<bits/stdc++.h>

using namespace std;

int N,S;

int arr[100001];
int visited[100001];

void bfs(int x) {
	int cnt =0;
	queue<int>q;
	visited[x]=1;
	q.push(x);
	while (!q.empty()) {
		x=q.front();
		q.pop();
		cnt++;
		int tx = x + arr[x];
		if (tx <= N&&!visited[tx]) {
			q.push(tx);
			visited[tx]=1;
		}
		tx =x-arr[x];
		if (tx > 0&&!visited[tx]) {
			q.push(tx);
			visited[tx]=1;
		}
	}
	cout <<cnt <<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> S;
	bfs(S);
	return 0;
}