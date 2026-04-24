#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	while (getline(cin, str)) {
		int pos;
		vector<string>tokens;
		while ((pos = str.find(" ")) != string::npos) {
			string token = str.substr(0, pos);
			tokens.push_back(token);
			str.erase(0, pos + 1);
		}
		tokens.push_back(str);

		int M, P, L, E, R, S, N;
		M = stoi(tokens[0]);
		P = stoi(tokens[1]);
		L = stoi(tokens[2]);
		E = stoi(tokens[3]);
		R = stoi(tokens[4]);
		S = stoi(tokens[5]);
		N = stoi(tokens[6]);

		ll dron = L;
		ll pupa = P;
		ll moskito = M;


		for (int i = 1; i <= N; i++) {

			ll next_dron = moskito * E;
			ll next_pupa = dron / R;
			ll next_moskito = pupa / S;

			dron = next_dron;
			pupa = next_pupa;
			moskito = next_moskito;
		}

		cout << moskito << '\n';
	}
	return 0;
}