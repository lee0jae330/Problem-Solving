#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>

#define INF 123456789

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

struct comp {
	bool operator()(pair<int, int>p1, pair<int, int>p2){
		return p1.first < p2.first;
	}
};

vector<pair<int, int>>v[1001];
vector<pair<int, int>>v1[1001];
int dist[1001];

int dest[1001];
priority_queue<pair<int, int>,vector<pair<int,int>>,comp>pq;


void dijk1(int x) {
	pq.push({ 0,x });
	dist[x] = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < d)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int cost = v[cur][i].second + d;
			if (cost < dist[v[cur][i].first]) {
				dist[v[cur][i].first] = cost;
				pq.push({ cost, v[cur][i].first });
			}
		}
	}
}
void dijk2(int x) {
	pq.push({ 0,x });
	dest[x] = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dest[cur] < d)
			continue;
		for (int i = 0; i < v1[cur].size(); i++) {
			int cost = v1[cur][i].second + d;
			if (cost < dest[v1[cur][i].first]) {
				dest[v1[cur][i].first] = cost;
				pq.push({ cost, v1[cur][i].first });
			}
		}
	}
}


int main(void) {
	fastio();
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v1[b].push_back({ a,cost });
	}
	int result = 0;
	memset(dest, INF, sizeof(dest));
	memset(dist, INF, sizeof(dist));
	dijk1(X);
	dijk2(X);
	for (int i = 1; i <= N; i++) {
		result = max(result, dist[i] + dest[i]);
	}
	cout << result << '\n';
	return 0;
}