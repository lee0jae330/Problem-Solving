#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void) {
	string a, b, c;
	string tmp;
	cin >> tmp;
	a = tmp.substr(0, 2);
	b = tmp.substr(3, 5);
	c = tmp.substr(6, 8);
	int n1 = stoi(a);
	int n2 = stoi(b);
	int n3 = stoi(c);
	int num = 0;
	if ((n1 < 0 || n1>59) || (n2 < 0 || n2>59) || (n3 < 0 || n3>59)) {
		cout << 0 << "\n";
	}
	else {
		if (n1 >= 1 && n1 <= 12)
			num++;
		if (n2 >= 1 && n2 <= 12)
			num++;
		if (n3 >= 1 && n3 <= 12)
			num++;
		cout << num * 2 << "\n";
	}

	return 0;
}