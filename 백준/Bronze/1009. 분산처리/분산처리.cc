#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		v.clear();
		int a, b;
		scanf("%d %d", &a, &b);
		if (a % 10 == 0)
		{
			printf("10\n");
			continue;
		}
		int tmp = a;
		while (1)
		{
			tmp %= 10;
			if (find(v.begin(), v.end(), tmp) == v.end())
			{
				v.push_back(tmp);
				tmp *= a;
			}
			else
				break;
		}
		if(v.size()==1)
			printf("%d\n", v[b % v.size()]);
		else
		{
			if(b%v.size()!=0)
				printf("%d\n", v[b %v.size()-1]);
			else
				printf("%d\n", v[v.size()-1]);

		}
	}
	return 0;
}