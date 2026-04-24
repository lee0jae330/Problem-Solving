#include<iostream>
#include<deque> 
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int>v(M);

	deque<int>dq;
	
	for (int i = 0; i < M; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	int sol = 0;
	for (int num : v) {
		while (dq.front() != num) {
			for (int i = 0; i < dq.size(); i++) {
				if (dq[i] == num) {
					if (i <= dq.size() / 2) {
						int tmp = dq.front();
						dq.pop_front();
						dq.push_back(tmp);
					}
					else {
						int tmp = dq.back();
						dq.pop_back();
						dq.push_front(tmp);
					}
					sol++;
				}
			}
		}
		dq.pop_front();
	}
	cout << sol <<'\n';
}