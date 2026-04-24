#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<pair<int, int>>table;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "order") {
			int num, time;
			cin >> num >> time;
			table.push_back({time, num });
		}
		else if (str == "sort") {
			sort(table.begin(), table.end());
		}
		else {
			int n;
			cin >> n;
			for (int i = 0; i < table.size(); i++) {
				if (table[i].second == n) {
					table.erase(table.begin() + i);
					break;
				}
			}
		}
		if (table.size() > 0) {
			for (int j = 0; j < table.size(); j++)
				cout << table[j].second << ' ';
			cout << "\n";
		}
		else {
			cout << "sleep" << "\n";
		}
	}
	return 0;
}