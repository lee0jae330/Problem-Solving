#include<iostream>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int arr[100][100];

int main(void) {
	fastio();
	int T;
	cin >> T;
	while (T > 0) {
		int H, W, N;
		cin >> H >> W >> N;
		int yy, xx;
		yy = N % H;
		xx = N / H + 1;
		if (yy){
			cout << yy;
		}
		else {
			cout << H;
			xx--;
		}
		if (xx < 10)
			cout << 0 << xx << '\n';
		else
			cout << xx << '\n';
		T--;
	}
	return 0;
}