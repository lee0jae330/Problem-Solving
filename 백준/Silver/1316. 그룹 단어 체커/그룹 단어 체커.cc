#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[102];
	int N;
	scanf("%d", &N);
	int count = 0;
	int tmp,input;
	char cur;
	for (int i = 0; i < N; i++)
	{
		input = 0;
		scanf("%s", str);
		for (int j = 0; j < strlen(str); j++)
		{
			tmp = 0;
			cur = str[j];
			if (cur == str[j + 1])
				continue;
			else
			{
				for (int k = j + 2; k < strlen(str); k++)
				{
					if (cur == str[k])
					{
						tmp++;
						break;
					}
				}
				if (tmp != 0)
					input++;
			}
		}
		if (input == 0)
			count++;
	}
	printf("%d\n", count);
	return 0;
}