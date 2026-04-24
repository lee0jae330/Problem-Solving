#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>A;
vector<int>B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	A.resize(N);
	B.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < N; i++) {
		A.push_back(A[i]);
		B.push_back(B[i]);
	}

	vector<int>lis;
	int scoreA = 0, scoreB = 0;
	for (int i = 0; i < N; i++) {
		lis.clear();
		for (int j = i; j < i + N; j++) {
			auto iter =lower_bound(lis.begin() ,lis.end(), A[j]);
			if (iter == lis.end()) {
				lis.push_back(A[j]);
			}
			else {
				*iter = A[j];
			}
		}
		scoreA=max((int)lis.size() , scoreA);
		lis.clear();
		for (int j = i; j < i + N; j++) {
			auto iter = lower_bound(lis.begin(), lis.end(), B[j]);
			if (iter == lis.end()) {
				lis.push_back(B[j]);
			}
			else {
				*iter =B[j];
			}
		}
		scoreB = max((int)lis.size(), scoreB);
	}

	if (scoreA > scoreB) {
		cout << "YJ Win!" <<'\n';
	}
	else if (scoreA < scoreB) {
		cout << "HG Win!" <<'\n';
	}
	else {
		cout << "Both Win!" <<'\n';
	}
	return 0;
}
