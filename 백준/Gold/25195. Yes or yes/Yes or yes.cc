#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

vector<int>v[100001];
int arr[100001];
int result, fan;
void bfs(int x) {
	queue < pair<int, int>>q;
    if(arr[x])
	    q.push({ x,1 });
    else
	    q.push({ x,0 });
        
	while (!q.empty()) {
		x = q.front().first;
		int flag = q.front().second;
		q.pop();
		if (!v[x].size()) {
				result++;
				if (flag||arr[x])
					fan++;
		}
		else {
			for (int i = 0; i < v[x].size(); i++) {
				if (flag) {
					q.push({ v[x][i],flag });
				}
				else {
					if (arr[v[x][i]]) {
						q.push({ v[x][i],1 });
					}
					else
						q.push({ v[x][i],0 });
				}
			}
		}
	}
}

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	int S;
	cin >> S;
	for (int i = 0; i < S; i++) {
		int num;
		cin >> num;
		arr[num] = 1;
	}
	bfs(1);
	if (result==fan)
		cout << "Yes" << '\n';
	else
		cout << "yes" << '\n';
	return 0;
}