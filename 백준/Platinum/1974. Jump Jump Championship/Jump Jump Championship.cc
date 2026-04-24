#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

vector<int>arr;
vector<int>lis;

int pre[10001];
vector<int>idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		arr.clear();
		lis.clear();
		idx.clear();
		memset(pre, 0, sizeof(pre));
		int N;
		cin >> N;
		arr.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < N; i++) {
			auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
			if (iter == lis.end()) {
				if (lis.size() == 0) {
					pre[i] = -1;
				}
				else {
					pre[i] = idx[idx.size() - 1];
				}
				lis.push_back(arr[i]);
				idx.push_back(i);
			}
			else {
				if (iter == lis.begin()) {
					pre[i] = -1;
				}
				else {
					pre[i] = idx[iter - lis.begin() - 1];
				}
				*iter = arr[i];
				idx[iter-lis.begin()] =i;
			}
		}
		cout << lis.size() <<'\n';

		stack<int>s;
		int tmp = idx[idx.size() -1];
		while (tmp != -1) {
			s.push(tmp);
			tmp = pre[tmp];
		}

		while (!s.empty()) {
			cout << s.top() + 1 << ' ';
			s.pop();
		}
		cout <<'\n';
	}
	return 0;
}