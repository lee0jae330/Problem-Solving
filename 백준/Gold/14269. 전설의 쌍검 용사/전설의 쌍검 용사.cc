#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

set<int>rh;
int arr[1000001];

vector<pair<pair<int, int>, int>>v;
set<int>lh;

bool comp(pair<pair<int, int>, int>p1, pair<pair<int, int>, int>p2) {
	if (p1.first.second == p2.first.second)
		return p1.first.first > p2.first.first;
	return p1.first.second < p2.first.second;
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		rh.insert(A);
		if (A == B && B == C) {
			if (!arr[A]) {
				v.push_back({ {B,C }, A });
				arr[A] = 1;
			}
		}
		else
			v.push_back({ {B,C},A });
	}
	sort(v.begin(), v.end(), comp);
	int result = rh.size();
	for (int i = 0; i < v.size(); i++) {
		auto iter = rh.lower_bound(v[i].first.first);
			if (iter != rh.end()) {
				if (*iter >= v[i].first.first && *iter <= v[i].first.second) {
					if (*iter == v[i].second) {
						if (lh.find(*iter) != lh.end()) {
							continue;
						}
						auto it = rh.upper_bound(*iter);
						if (it == rh.end()) {
							result++;
							lh.insert(v[i].second);
						}
						else {
							if (*it > v[i].first.second || *it < v[i].first.first) {
								result++;
								lh.insert(v[i].second);
							}
						}
					}
				}
				else {
					result++;
					rh.insert(v[i].first.second);
				}
			}
			else {
				result++;
				rh.insert(v[i].first.second);
			}
	}
	cout << result << '\n';
	return 0;
}