#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

vector<string>v;
map<string, int>m;

bool cmp2(string s1, string s2)
{
	if (s1.length() < s2.length())
		return true;
	else if (s1.length() > s2.length())
		return false;
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] > s2[i])
				return false;
			else if (s1[i] < s2[i])
				return true;
				
		}
	}
}

bool cmp(string s1, string s2)
{
	string c1 = s1 + s2;
	string c2 = s2 + s1;
	return c1 > c2;
}

int main(void)
{
	int N, K;
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
	{
		char num[11];
		scanf("%s", &num);
		string str(num);
		if (m.find(str) != m.end())
			m[str]++;
		else
		{
			m.insert({ str,1 });
			v.push_back(str);
		}
	}
	sort(v.begin(), v.end(),cmp2);

	int tmp = N - K;
	m[v[v.size() - 1]] += tmp;
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		const char* arr = v[i].c_str();
		for (int j = 0; j < m[v[i]]; j++)
			printf("%s", arr);
	}

	return 0;
}