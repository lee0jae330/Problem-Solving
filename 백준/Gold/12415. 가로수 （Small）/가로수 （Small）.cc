#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<pair<int, int>>v;

bool comp(pair<int, int>p1, pair<int, int>p2) {
	return p1.first < p2.first;
}

int main(void) {
	fastio();
	int T, idx = 1;
	cin >> T;
	while (T > 0) {
		int flag = 0;
		T--;
		int N, M, B;
		cin >> N >> M >> B;
		for (int i = 0; i < M; i++) {
			int p, q;
			cin >> p >> q;
			v.push_back({ p,q });
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		int result = 0;
		auto it = lower_bound(v.begin(), v.end(), make_pair(B,0),comp);
		if (it!=v.end()&&it->first == B) {
			while (it->second > 0) {
				cnt++;
				result += it->first;
				if (cnt == N)
					break;
				it->second--;
			}
		
		}
		if (cnt >= N) {
			cout << "Case #" << idx << ": " << result << '\n';
		}
		else {

			int num = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v[i].second != 0)
					num += v[i].second;
			}
			int rec = num;
			while (rec>0) {
				if (cnt == N)
					break;
				int mn = 1000000000;
				int index1 = -1, index2 = -1;
				int flag = 0;
				for (int i = 0; i < v.size(); i++) {
					int n1 = -1,n2;
					int tmp;
					if (v[i].second > 0) {
						n1 = v[i].first;
					}
					if (n1 == -1)
						continue;
					if (n1 >= B) {
						tmp = n1;
						if (mn > tmp) {
							mn = tmp;
							index1 = i;
							flag = 0;
						}
					}
					else {
						n2 = B - n1;
						auto iter = lower_bound(v.begin(), v.end(), make_pair(n2, 0), comp);
						if (iter->second == 0 || (n1 == iter->first && iter->second == 1)||iter->first+n1<B ) {
							while (1) {
								if (iter->second == 0 || iter->first + n1 < B || (n1 == iter->first && iter->second == 1)) {
									int tmptmp = iter->first;
									iter = upper_bound(v.begin(), v.end(), make_pair(tmptmp, 0), comp);

								}
								else
									break;
								if (iter == v.end())
									break;
							}
						}
						if (iter == v.end()) {
							flag = -1;
							continue;
						}
						tmp = n1 + iter->first;
						flag = 1;
						if (flag == 1) {
							if (mn > tmp) {
								mn = tmp;
								index1 = i;
								index2 = iter - v.begin();
							}
						}
					}
					
					
				}
				rec--;
				if (mn != 1000000000) {
					result += mn;
					cnt++;
					v[index1].second--;
					if (flag==1) {
						v[index2].second--;
					}
				}
			}
			if(cnt>=N)
				cout << "Case #" << idx << ": " << result << '\n';
			else
				cout << "Case #" << idx << ": " <<-1 << '\n';

		}
		idx++;
		v.clear();
	}
	return 0;
}