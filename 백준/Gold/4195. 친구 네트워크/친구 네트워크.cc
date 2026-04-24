#include<iostream>
#include<map>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

map<string, int>m;
int parent[200002];
map<int, int> friends;

void init(int n) {
	for (int i = 0; i <= n; i++)
		parent[i] = i;
}

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (x > y) {
			parent[x] = y;
			if (friends.find(y) != friends.end()) {
				if (friends.find(x) == friends.end()) {
					friends[y]++;
				}
				else{
					friends[y] += friends[x];
				}
			}
			else {
				if (friends.find(x) == friends.end())
					friends.insert({ y,2 });
				else {
					friends.insert({ y,1+friends[x] });
				}
			}
		}
		else {
			parent[y] = x;
			if (friends.find(x) != friends.end()) {
				if (friends.find(y) == friends.end()) {
					friends[x]++;
				}
				else {
					friends[x] += friends[y];
				}
			}
			else {
				if (friends.find(y) == friends.end())
					friends.insert({ x,2 });
				else
					friends.insert({ x,1 + friends[y] });
			}
		}
	}
}

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T > 0) {
		int F;
		cin >> F;
		init(2*F);
		m.clear();
		friends.clear();
		int sz = m.size();

		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;
			if (m.find(a) == m.end()) {
				m.insert({ a,sz });
				sz++;
			}

			if (m.find(b) == m.end()) {
				m.insert({ b, sz});
				sz++;
			}
			merge(m[a], m[b]);
			int tmp = Find(m[a]);
			
			cout << friends[tmp] << '\n';
		}
		T--;
	}
}