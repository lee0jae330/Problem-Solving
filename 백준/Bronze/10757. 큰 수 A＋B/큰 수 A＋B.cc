#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

string add(string a, string b)
{
	int sum = 0;
	string result;
	while (!a.empty() || !b.empty() || sum)
	{
		if (!a.empty())
		{
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty())
		{
			sum += b.back() - '0';
			b.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main(void)
{
	int N;
	char str[10005];
	char str1[10005];
	scanf("%s %s", str, str1);
	string a = str;
	string b = str1;
	strcpy(str, add(a, b).c_str());
	printf("%s\n", str);
	return 0;
}