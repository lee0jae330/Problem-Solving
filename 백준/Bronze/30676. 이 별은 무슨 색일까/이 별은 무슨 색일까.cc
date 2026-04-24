#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if (n >= 620)
		cout << "Red" << '\n';
	else if(n>=590)
		cout << "Orange" << '\n';
	else if (n >= 570)
		cout << "Yellow" << '\n';
	else if (n >= 495)
		cout << "Green" << '\n';
	else if (n >= 450)
		cout << "Blue" << '\n';
	else if (n >= 425)
		cout << "Indigo" << '\n';
	else 
		cout << "Violet" << '\n';
	return 0;
}