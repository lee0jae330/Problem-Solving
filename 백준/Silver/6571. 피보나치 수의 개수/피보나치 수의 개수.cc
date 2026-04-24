#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
string add(string s1, string s2);
string sub(string s1, string s2);



string add(string s1, string s2) {
	char op1 = s1[0], op2 = s2[0];
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	string result = "";
	if (op1 == '-' && op2 == '-') {
		if (s1.size() < s2.size()) {
			swap(s1, s2);
		}
		int flag = 0;
		for (int i = 0; i < s2.size() - 1; i++) {
			int c1 = s1[i] - '0', c2 = s2[i] - '0';
			int a = c1 + c2 + flag;
			int x = a / 10;
			a %= 10;
			char n = a + '0';
			flag = 0;
			result.push_back(n);
			if (x)
				flag = 1;
			else
				flag = 0;
		}
		for (int i = s2.size() - 1; i < s1.size() - 1; i++) {
			int a = s1[i] + flag - '0';
			int x = a / 10;
			a %= 10;
			char n = a + '0';
			result.push_back(n);
			flag = 0;
			if (x)
				flag = 1;
			else
				flag = 0;
		}
		if (flag == 1)
			result.push_back('1');
		result.push_back('-');
	}
	else if (op1 == '-' || op2 == '-') {
		if (op1 == '-') {
			s1.pop_back();
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			return sub(s2, s1);
		}
		else {
			s2.pop_back();
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			return sub(s1, s2);
		}
	}
	else {
		if (s1.size() < s2.size()) {
			swap(s1, s2);
		}
		int flag = 0;
		for (int i = 0; i < s2.size(); i++) {
			int c1 = s1[i] - '0', c2 = s2[i] - '0';
			int a = c1 + c2 + flag;
			int x = a / 10;
			a %= 10;
			char n = a + '0';
			flag = 0;
			result.push_back(n);
			if (x)
				flag = 1;
			else
				flag = 0;
		}
		for (int i = s2.size(); i < s1.size(); i++) {
			int a = s1[i] + flag - '0';
			int x = a / 10;
			a %= 10;
			char n = a + '0';
			result.push_back(n);
			flag = 0;
			if (x)
				flag = 1;
			else
				flag = 0;
		}
		if (flag == 1)
			result.push_back('1');
	}
	reverse(result.begin(), result.end());
	return result;
}

string sub(string s1, string s2) {
	char op1 = s1[0], op2 = s2[0];
	if (op1 == '-' && op2 == '-') {
		s1 = s1.substr(1, s1.size());
		s2 = s2.substr(1, s2.size());
		return sub(s2, s1);
	}
	else if (op1 == '-' || op2 == '-') {
		if (op1 == '-') {
			s1 = s1.substr(1, s1.size());
			string tmp = add(s1, s2);
			reverse(tmp.begin(), tmp.end());
			tmp.push_back('-');
			reverse(tmp.begin(), tmp.end());
			return tmp;
		}
		if (op2 == '-') {
			s2 = s2.substr(1, s2.size());
			return add(s1, s2);
		}
	}
	else { // 양수 양수
		string result;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		if (s1.size() < s2.size()) {
			swap(s1, s2);
			int flag = 0;
			for (int i = 0; i < s2.size(); i++) {
				int n1 = s1[i] - '0', n2 = s2[i] - '0';
				int sum = n1 - n2 - flag;
				int x = 0;
				if (sum < 0) {
					flag = 1;
					x = 1;
					sum += 10;
				}
				char num = sum + '0';
				result.push_back(num);
				if (!x)
					flag = 0;
			}
			for (int i = s2.size(); i < s1.size(); i++) {
				int n1 = s1[i] - flag - '0';
				int x = 0;
				if (n1 < 0) {
					flag = 1;
					x = 1;
					n1 += 10;
				}
				char num = n1 + '0';
				if (i == s1.size() - 1 && n1 == 0)
					break;
				result.push_back(num);
				if (!x)
					flag = 0;
			}
			while (result.size() > 1 && result.back() == '0') {
				result.pop_back();
			}
			result.push_back('-');
		}
		else if (s1.size() > s2.size()) {
			int flag = 0;
			for (int i = 0; i < s2.size(); i++) {
				int n1 = s1[i] - flag - '0', n2 = s2[i] - '0';
				int sum = n1 - n2;
				int x = 0;
				if (sum < 0) {
					flag = 1;
					x = 1;
					sum += 10;
				}
				char num = sum + '0';
				result.push_back(num);
				if (!x)
					flag = 0;
			}
			for (int i = s2.size(); i < s1.size(); i++) {
				int n1 = s1[i] - flag - '0';
				int x = 0;
				if (n1 < 0) {
					flag = 1;
					x = 1;
					n1 += 10;
				}
				char num = n1 + '0';
				if (i == s1.size() - 1 && n1 == 0)
					break;
				result.push_back(num);
				if (!x)
					flag = 0;
			}
			while (result.size() > 1 && result.back() == '0') {
				result.pop_back();
			}
		}
		else {
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			int check = 0;
			for (int i = 0; i < s1.size(); i++) {
				if (s1[i] < s2[i]) {
					swap(s1, s2);
					check = 1;
					break;
				}
				else if (s1[i] > s2[i]) {
					check = -1;
					break;
				}
			}
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			if (check == 1) { // 111 - 222
				int flag = 0;
				for (int i = 0; i < s2.size(); i++) {
					int n1 = s1[i] - flag - '0', n2 = s2[i] - '0';
					int sum = n1 - n2;
					int x = 0;
					if (sum < 0) {
						flag = 1;
						x = 1;
						sum += 10;
					}
					char num = sum + '0';
					if (i == s2.size() - 1 && sum == 0)
						break;
					result.push_back(num);
					if (!x)
						flag = 0;
				}
				while (result.back() == '0')
					result.pop_back();
				result.push_back('-');
			}
			else if (check == -1) { // 222 - 111
				int flag = 0;
				for (int i = 0; i < s2.size(); i++) {
					int n1 = s1[i] - flag - '0', n2 = s2[i] - '0';
					int sum = n1 - n2;
					int x = 0;
					if (sum < 0) {
						flag = 1;
						x = 1;
						sum += 10;
					}
					char num = sum + '0';
					if (i == s2.size() - 1 && sum == 0)
						break;
					result.push_back(num);
					if (!x)
						flag = 0;
				}
				while (result.back() == '0')
					result.pop_back();
			}
			else { /// 11 -11
				result.push_back('0');
			}
		}

		reverse(result.begin(), result.end());
		return result;
	}
}

vector<string> v;

void fibo(int n) {
	if (n == 1) {
		v.push_back("1");
	}
	else if (n == 2)
		v.push_back("2");
	else {
		v.push_back(add(v[n - 2], v[n - 3]));
	}
}

int main(void) {
	fastio();
	//cout << add(n1, n2) << "\n";
	//cout << sub(n1, n2) << "\n";
	for (int i = 1; i <= 1000; i++) {
		fibo(i);
	}
	while (1)
	{
		string s1, s2;

		cin >> s1 >> s2;
		if (s1 == "0" && s2 == "0") {
			return 0;
		}
		int min=-1, max=-1;
		int f = 0;
		for (int i = 0; i < v.size(); i++) {
			f = 0;
			if (s1.size() == v[i].size()) {
				for (int j = 0; j < s1.size(); j++) {
					if (s1[j] < v[i][j]) {
						min = i;
						f = 1;
						break;
					}
					else if (s1[j] > v[i][j]) {
						f = -1;
						break;
					}
				}
				if (f == 1)
					break;
				else if (f==0) {
					min = i;
					break;
				}

			}
			else if (s1.size() < v[i].size()) {
				min = i;
				break;
			}
		}
		for (int i = min; i < v.size(); i++) {
			f = 0;
			if (s2.size() == v[i].size()) {
				for (int j = 0; j < v[i].size(); j++) {
					if (s2[j] > v[i][j]) {
						f = -1;
						break;
					}
					if (s2[j] < v[i][j]) {
						f = 1;
						break;
					}
				}
			}
			else if (s2.size() < v[i].size()) {
				max = i - 1;
				break;
			}
			if (f == 1) {
				max = i - 1;
				break;
			}
		}
		cout << max - min + 1 << "\n";

	}
	return 0;
}