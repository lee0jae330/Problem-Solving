#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

map<string, string> m;

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string group;
		cin >> group;
		int number;
		cin >> number;
		for (int j = 0; j < number; j++) {
			string name;
			cin >> name;
			m.insert({ name, group });
		}
	}
	for (int i = 0; i < M; i++) {
		int f;
		string name;
		cin >> name;
		cin >> f;
		if (f) {
			cout << m[name] << '\n';
		}
		else {
			for (auto iter = m.begin(); iter != m.end(); iter++) {
				if(iter->second==name)
					cout << iter->first << '\n';
			}
		}
	}
	return 0;
}