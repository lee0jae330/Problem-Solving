#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

vector<long long int>v;

int main(void)
{
	int T;
	scanf("%d", &T);
	getchar();
	for (int i = 1; i <= T; i++)
	{
		v.clear();
		long long int a, b, c;
		scanf("%lld", &a);
		getchar(); 
		scanf("%lld", &b);
		getchar();
		scanf("%lld", &c);
		getchar();
		v.push_back(a), v.push_back(b), v.push_back(c);
		sort(v.begin(), v.end());
		printf("Scenario #%d: \n", i);
		if (pow(v[2], 2) == pow(v[0], 2) + pow(v[1], 2))
			printf("yes \n");
		else
			printf("no \n");
		if(i<T)
			printf("\n");
	}
	return 0;
}