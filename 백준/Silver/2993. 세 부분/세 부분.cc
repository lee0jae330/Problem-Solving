#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


string swaping(string str, int first, int second, int third) {
	int idx1 = 0, end1=idx1+first-1;
	int idx2 = first, end2=idx2+second-1;
	int idx3 = first + second, end3=idx3+third-1;
	
	for (int i = 0; i < first / 2; i++) {
		swap(str[idx1 + i], str[end1 - i]);
	}
	for (int i = 0; i < second / 2; i++) {
		swap(str[idx2 + i], str[end2 - i]);
	}
	for (int i = 0; i < third / 2; i++) {
		swap(str[idx3 + i], str[end3 - i]);
	}
	return str;
}

int main(void) {
	fastio();
	string str;
	cin >> str;
	if (str.size() == 3) {
		cout << str << '\n';
		return 0;
	}
	int len = str.size();
	string tmp = swaping(str, 1, 1,len-2);

	for (int i = 1; i < len; i++) {
		string s1;
		for (int j = 1; j < len - i; j++) {
			s1 = swaping(str, i, j, len - i - j);
			if (s1 < tmp) {
				tmp = s1;
			}
		}
	}
	cout << tmp << '\n';
	return 0;
}