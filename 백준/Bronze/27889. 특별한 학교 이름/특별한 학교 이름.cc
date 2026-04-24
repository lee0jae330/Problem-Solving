#include<bits/stdc++.h>

using namespace std;

int main(void) {
	string name;
	cin >> name;
	if (name[0] == 'N') {
		cout << "North London Collegiate School" <<'\n';
	}
	else if (name[0] == 'B') {
		cout << "Branksome Hall Asia" <<'\n';
	}
	else if (name[0] == 'K') {
		cout << "Korea International School" <<'\n';
	}
	else if(name[0] =='S') {
		cout << "St. Johnsbury Academy" <<'\n';
	}
	return 0;
}