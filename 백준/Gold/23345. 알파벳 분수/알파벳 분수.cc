#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int arr[26];

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


vector<pair<char, int >>v;

bool comp(pair<char, int > p1, pair<char, int >p2) {
	return p1.first < p2.first;
}

int main(void) {
	fastio();
	string str;
	cin >> str;
	int flag = 0;
	int s = str.size();
	int f = 0;
	for (int i = 0; i < str.size(); i++) {
		int num;
		if (str[i] == '/') {
			if (i == str.size() - 1)
				flag = 1;
			f = 1;
			s--;
			continue;
		}
		num = str[i] - 'A';
		if (arr[num]) {
			flag = 1;
			break;
		}
		else {
			arr[num] = 1;
			if (!f)
				v.push_back({ str[i],1 });
			else
				v.push_back({ str[i],0 });
		}
		if ((f&&!num)||(!f && num == 1)) {
			flag = 1;
			break;
		}
	}
	for (int i = 0; i < s; i++) {
		if (!arr[i]) {
			flag = 1;
			break;
		}
	}
	if (!f)
		flag = 1;
	if (flag) {
		cout << "None" << '\n';
	}
	else {
		sort(v.begin(), v.end(), comp);

		for (int i = 1; i < v.size(); i++) {
			if (v[i].second) 
				v[i].second = 0;
			else
				v[i].second = 1;
		}
		
		queue<string>comb;
		
		stack<string> tp;
		for (int i = 0; i < v.size(); i++) {
			string tmp;
			if (!v[i].second)
				continue;
			if (v[i].second && i == v.size() - 1) {
				tmp.push_back(v[i].first);
				comb.push(tmp);
			}
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j].second) {
					if (tp.empty()) {
						tmp.push_back(v[i].first);
						comb.push(tmp);
					}
					else {
						comb.push(tp.top());
						tp.pop();

					}
					i = j - 1;
					break;
				}
				else {
					string still_loop;
					if (!tp.empty()) {
						still_loop.push_back('(');
						still_loop += tp.top();
						tp.pop();
						still_loop.push_back('/');
						still_loop.push_back(v[j].first);
						still_loop.push_back(')');
						tp.push(still_loop);
					}
					else {
						still_loop.push_back('(');
						still_loop.push_back(v[i].first);
						still_loop.push_back('/');
						still_loop.push_back(v[j].first);
						still_loop.push_back(')');
						tp.push(still_loop);
					}
						
				}
			}
		}
		if (!tp.empty()) {
			comb.push(tp.top());
			tp.pop();
		}
		s = comb.size() - 1;
		string result;
		for (int i = 0; i < s; i++) {
			result += "(";
		}
		s= comb.size();
		while (!comb.empty()) {
			if (s == comb.size()) {
				result += comb.front();
				comb.pop();
				if (s == 1) {
					result += ")";
				}
			}
			else {
				result += '/';
				result += comb.front();
				comb.pop();
				result += ')';
			}
		}
		cout << result << '\n';

	}
	return 0;
}