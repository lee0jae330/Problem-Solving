#include<iostream>
#include<vector>
#include<set> 
#include<algorithm>

using namespace std;

int N, M;
int visited[10];
vector<int>v;
vector<int>arr;
set<vector<int>>s;

void backtrack() {
	if (arr.size() == M) {
		s.insert(arr);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			arr.push_back(v[i]);
			backtrack();
			visited[i] = 0;
			arr.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	backtrack();

	for (vector<int> vt : s) {
		for (int num : vt) {
			cout << num << ' ';
		}
		cout <<'\n';
	}

	return 0;
}