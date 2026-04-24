#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, c, tmp;
	cin >> t;
	while (t--)
	{
		cin >> n >> c;
		tmp = n / c;
		if (n % c)
			tmp++;
		cout << tmp << "\n";
	}
	return 0;
}