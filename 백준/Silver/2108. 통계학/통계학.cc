#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

vector<int>v;
vector<pair<int, int>>v2;


void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

bool compare(pair<int, int>p1, pair<int, int>p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first > p2.first;
}

int main(void) {
	fastio();
	int N;
	cin >> N;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		int flag = 0;
		int num;
		cin >> num;
		sum += num;
		v.push_back(num);
		for (auto iter = v2.begin(); iter != v2.end(); iter++) {
			if (iter->second == num)
			{ 
				iter->first++;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			v2.push_back({ 1,num });
		}
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end(),compare);
	/*for (int i = 0; i < v2.size(); i++) {
		cout << v2[i].first << ' ' << v2[i].second << '\n';
	}*/
	int sol = v2[0].first;
	int cnt=1;
	for (int i = 1; i < v2.size(); i++) {
		if (v2[i].first == sol) {
			cnt++;
		}
		else
			break;
	}
	if (cnt == 1)
		sol = v2[0].second;
	else
		sol = v2[1].second;
	
	cout << floor(sum/N+0.5) << '\n';
	cout << v[N / 2] << '\n';
	cout << sol << '\n';
	cout << v[N - 1] - v[0] << '\n';
	return 0;
}