#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}



int main(void) {
	int T;
	cin >> T;
	while (T > 0) {
		priority_queue<int>pq;
		queue<pair<int, int>>q;
		int N, M, cnt=1;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			q.push({ num,i });
			pq.push(num);
		}
		while (1) {
			int mx = pq.top();
			if (mx == q.front().first) {
				int s = q.front().second;
				q.pop();
				pq.pop();
				if (s == M)
					break;
				cnt++;
			}
			else {
				pair<int, int>p = q.front();
				q.pop();
				q.push(p);
			}
		}
		cout << cnt << '\n';
		T--;
	}
	return 0;
}