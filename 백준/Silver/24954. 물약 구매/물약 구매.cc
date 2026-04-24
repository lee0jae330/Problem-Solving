#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int arr[12];
int dis[12];
int degree[12];
int connect[12][12];
int visited[12];

int max_degree;
vector<pair<int, int>>v[12];
int N;
int result = 0;

int cp[12];

void init() {
	for (int i = 1; i <= N; i++)
		cp[i] = arr[i];
}


int main(void) {
	fastio();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dis[i] = arr[i];
		result += arr[i];
	}


	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int a, cost;
			cin >> a >> cost;
			v[i].push_back({ a,cost });
		}
	}
	vector<int> sol;
	for (int i = 0; i < N; i++) {
		sol.push_back(i+1);
	}


	int tmp = 0;
	do {
		init();
		tmp =0;
		/*for(int i=0;i<sol.size();i++)
			cout << sol[i] <<' ';
		cout <<'\n';*/
		for (int i = 0; i < sol.size(); i++) {
			int cur = sol[i];
			//cout << cur <<'\n';
			tmp += cp[cur];
			for (int j = 0; j < v[cur].size(); j++) {
				int next = v[cur][j].first;
				int c = v[cur][j].second;
				cp[next] -= c;
				if (cp[next] < 1)
					cp[next] = 1;
			}
		}
		result = min(result, tmp);
	} while (next_permutation(sol.begin(), sol.end()));
	cout <<result <<'\n';
	return 0;
}