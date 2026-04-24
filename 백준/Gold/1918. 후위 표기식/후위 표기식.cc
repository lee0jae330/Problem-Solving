#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

int isp[] = { 0,19,12,12,13,13,0 };
int icp[] = { 20,19,12,12,13,13,0 };

int post(char c1, char c2) // c1이 들어올거, c2 stack top
{
	int n1, n2;
	switch (c1)
	{
	case '(':
		n1 = 0;
		break;
	case ')':
		n1 = 1;
		break;
	case '+':
		n1 = 2;
		break;
	case '-':
		n1 = 3;
		break;
	case '*':
		n1 = 4;
		break;
	default:
		n1 = 5;
		break;
	}
	switch (c2)
	{
	case '(':
		n2 = 0;
		break;
	case ')':
		n2 = 1;
		break;
	case '+':
		n2 = 2;
		break;
	case '-':
		n2 = 3;
		break;
	case '*':
		n2 = 4;
		break;
	default:
		n2 = 5;
		break;
	}
	if (icp[n1] <= isp[n2])
		return 1;
	else
		return 0;
}

int rparen(char c2)
{
	int n2;
	switch (c2)
	{
	case '(':
		n2 = 0;
		break;
	case ')':
		n2 = 1;
		break;
	case '+':
		n2 = 2;
		break;
	case '-':
		n2 = 3;
		break;
	case '*':
		n2 = 4;
		break;
	default:
		n2 = 5;
		break;
	}
	if (n2 == 0)
		return 1;
	else
		return 0;
}


int main(void)
{
	stack<char>s;
	char str[102];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			printf("%c", str[i]);
		else
		{
			if (s.empty())
			{
				s.push(str[i]);
			}
			else
			{
				if (str[i] == ')')
				{
					while (!rparen(s.top()))
					{
						printf("%c", s.top());
						s.pop();
					}
					s.pop();
				}
				else
				{
					if (post(str[i], s.top()) == 1)
					{
						while (!s.empty()&& post(str[i], s.top()))
						{
								printf("%c", s.top());
								s.pop();
						}
						s.push(str[i]);
					}
					else
						s.push(str[i]);
				}
			}
		}
	}
	while (!s.empty())
	{
		printf("%c", s.top());
		s.pop();
	}
	return 0;
}