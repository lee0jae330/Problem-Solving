#include<iostream>

#include<map>

#include<string>

#include<vector>

#include<algorithm>

using namespace std;

map<string, int >m;

vector<int>v;

int main(void) {

	int N;	cin >> N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < 4; j++) {

			for (int k = 0; k < 7; k++) {

				string s;

				cin >> s;

				if (s == "-")

					continue;

				if (j == 0) {

					if (m.find(s) == m.end()) {

						m.insert({ s,4 });

					}

					else {

						m[s] += 4;

					}

				}

				else if (j == 1) {

					if (m.find(s) == m.end()) {

						m.insert({ s,6 });

					}

					else {

						m[s] += 6;

					}

				}

				else if (j == 2) {

					if (m.find(s) == m.end()) {

						m.insert({ s,4 });

					}

					else {

						m[s] += 4;

					}

				}

				else if (j == 3) {

					if (m.find(s) == m.end()) {

						m.insert({ s,10 });

					}

					else {

						m[s] += 10;

					}

				}

			}

		}

	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {

		v.push_back(iter->second);

	}

	sort(v.begin(), v.end());

	if (v.size() <= 1)

		cout << "Yes" << '\n';

	else {

		if (v[v.size() - 1] - v[0] > 12)

			cout << "No" << '\n';

		else

			cout << "Yes" << '\n';

	}

	

}

 