#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

map<int, int>m;

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		if (i == 0)
		{
			scanf("%d", &num);
			m.insert({ num,1 });
		}
		else
		{
			scanf("%d", &num);
			if (m.find(num) != m.end())
				m[num]++;
			else
				m.insert({ num, 1 });
		}
	}
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (m.find(tmp) != m.end())
		{
			printf("%d ", m[tmp]);
		}
		else
			printf("0 ");
	}
	printf("\n");
	return 0;
}