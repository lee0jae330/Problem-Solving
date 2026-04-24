#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;

long long int s, t;
queue<long long int>q;
map<long long int, long long int>m;
set<long long int>visit;

void bfs(long long int x)
{
	visit.insert(x);
	q.push(x);
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		if (x == t)
			return;
		if ( visit.find(x*x)==visit.end())
		{
			if (x * x <= t)
			{
				visit.insert(x * x);
				q.push(x * x);
				m.insert({ x * x,x });
			}
		}
		if (visit.find(x + x) == visit.end())
		{
			if (x + x <= t)
			{
				visit.insert(x + x);
				q.push(x + x);
				m.insert({ x + x,x });
			}
		}
		if (x > 0 && visit.find(x / x) == visit.end())
		{
			visit.insert(x / x);
			q.push(x / x);
			m.insert({ x / x,x });
		}
	}
}

int main(void)
{
	scanf("%lld %lld", &s, &t);
	if (s == t)
	{
		printf("0\n");
		return 0;
	}
	bfs(s);
	long long int tmp = t;
	stack<long long int>stk;
	if (m.find(tmp) == m.end())
	{
		printf("-1\n");
		return 0;
	}
	while (tmp != s)
	{
		stk.push(tmp);
		tmp = m[tmp];
		
	}
	long long int a = s;
	while (!stk.empty())
	{
		tmp = stk.top();
		if (tmp == 1)
			printf("/");
		else if (tmp / a == a)
			printf("*");
		else if (tmp / a == 2)
			printf("+");
		a = tmp;
		stk.pop();
	}
	printf("\n");
	return 0;
}