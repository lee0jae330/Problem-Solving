#include<iostream>
#include<string>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main(void) {
	fastio();
	int A, B;
	string C;
	cin >> A >> B >> C;
	int num = A ^ B, last= C[C.length()-1]-'0';
	
	if (last%2)
		cout << num << '\n';
	else
		cout << A << '\n';
	return 0;
}