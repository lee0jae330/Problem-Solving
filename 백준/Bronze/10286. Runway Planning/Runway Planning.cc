#include<iostream>
#include<math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >>T;
	while (T--) {
		int num;
		cin >> num;
		
		if(num >= 180)
			num -= 180;
		int result = num / 10;
		result += (num % 10 >= 5) ? 1 : 0;
		if (!result) {
			cout << 18 <<'\n';
		}
		else if(result < 10){
			cout <<0 << result <<'\n';
		}
		else {
			cout <<result <<'\n';
		}
	}
	return 0;
}