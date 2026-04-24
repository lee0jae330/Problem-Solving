#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

string fibo[10001];

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
	scanf("%d", &N);
	fibo[0] = '0';
	fibo[1] = '1';
	for (int i = 2; i <= N; i++)
	{
		fibo[i] = add(fibo[i - 1], fibo[i - 2]);
	}
	strcpy(str, fibo[N].c_str());
	printf("%s\n", str);
	return 0;
}