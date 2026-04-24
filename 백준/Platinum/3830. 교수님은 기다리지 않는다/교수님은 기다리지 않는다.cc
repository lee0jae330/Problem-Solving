#include<iostream>
#include<memory.h>
#include<string.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int parent[100002];
long long int weight[100002];
bool check;

void init() {
	for (int i = 0; i < 100002; i++) {
		parent[i] = i;
	}
}

int Find(int x) {
	if (x == parent[x])
		return x;
	else {
		int p = Find(parent[x]);
		weight[x] += weight[parent[x]];
		return parent[x] = p;
	}
}

void merge(int x, int y,long long int w) {
	int X = x, Y = y;
	x = Find(x);
	y = Find(y);
	check = false;
	if (x != y) {
			weight[y] = weight[X] - weight[Y] + w;
			parent[y] = x;

	}
}

int main(void) {
	fastio();

	while (1) {
		init();
		memset(weight, 0,sizeof(weight));
		int N, M;
		cin >> N >> M;
		if (!N && !M)
			break;
		for (int i = 0; i < M; i++) {
			char c;
			int a, b;
			long long int w;
			cin >> c;
			if (c == '!') {
				cin >> a >> b >> w;
				merge(a, b,w);
			}
			else {
				cin >> a >> b;
				int x = Find(a);
				int y = Find(b);
				if (x == y) {
					cout << weight[b] - weight[a] << '\n';
				}
				else
					cout << "UNKNOWN" << '\n';
			}
		}
	}
	return 0;
}