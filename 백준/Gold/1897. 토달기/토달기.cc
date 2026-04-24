//*g5 & #bfs & !@$me & %ko

#include<bits/stdc++.h>

using namespace std;

int d;

vector<string> dic;
map<int,set<string>>m; // 문자열 크기, 해당 문자열들
set<string> visited;
string start;

string sol;

void bfs(string str) {
	int mx = 0;
	queue<string>q;
	visited.insert(str);
	q.push(str);
	sol = str;
	mx = str.size();
	while (!q.empty()) {
		str = q.front();
		q.pop();
		if (mx < str.size()) {
			mx = str.size();
			sol = str;
		}
		int sz = str.size();
		if(m.find(sz+1)==m.end())
			continue;
		set<string>tmp = m[sz+1];
		for (string s : tmp) {
			if(visited.find(s)!=visited.end())
				continue;
			int flag =0;
			int idx1 = 0, idx2 =0;
			while (idx1 < sz) {
				if (str[idx1] == s[idx2]) {
					idx1++;
					idx2++;
				}
				else {
					idx2++;
					flag++;
				}
				if(flag==2)
					break;
			}
			if (flag <= 1) {
				q.push(s);
				visited.insert(s);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> d >> start;
	for (int i = 0; i < d; i++) {
		string str;
		cin >> str;
		dic.push_back(str);
		if (m.find(str.size()) == m.end()) {
			set<string>tmp;
			tmp.insert(str);
			m.insert({str.size(),tmp});
		}
		else
			m[str.size()].insert(str);
	}
	bfs(start);
	cout << sol <<'\n';
	return 0;
}