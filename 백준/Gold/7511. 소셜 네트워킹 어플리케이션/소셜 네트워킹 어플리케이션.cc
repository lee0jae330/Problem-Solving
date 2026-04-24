#include<iostream>
#include<memory.h>
#include<string.h>
#include<vector>

using namespace std;

int parent[1000001];
vector<int> v;
void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

int find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		if (x > y)
			parent[x] = y;
		else
			parent[y] = x;
	}
}

int main(void) {
	int T,cnt=1;
	cin >> T;
	while (T-->0) {
		memset(parent, 0, sizeof(parent));
		v.clear();
		int n;
		cin >> n;
		init(n);
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			merge(a, b);
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (find(a) == find(b))
				v.push_back(1);
			else
				v.push_back(0);
		}
		cout << "Scenario " << cnt << ":\n";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
		cout << '\n';
		cnt++;
	}
	return 0;
}