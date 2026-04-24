#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;

char str[102];
double arr[27];
int main(void)
{
	int N;
	stack<double>s;
	scanf("%d", &N);
	scanf("%s", str);
	for (int i = 0; i < N; i++)
		scanf("%lf", &arr[i]);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			s.push(arr[str[i] - 65]);
		}
		else
		{
			double n2 = s.top();
			s.pop();
			double n1 = s.top();
			s.pop();
			if (str[i] == '+')
			{
				s.push(n1 + n2);
			}
			else if(str[i]=='-')
			{
				s.push(n1 - n2);
			}
			else if (str[i] == '*')
			{
				s.push(n1 * n2);
			}
			else
			{
				s.push(n1 / n2);
			}
		}
	}
	printf("%.2lf\n", s.top());
	return 0;
}