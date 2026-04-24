#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int num, N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char str[100];
		scanf("%d %s",&num, str);
		getchar();
		char str1[100]="";
		int k = 0;
		for (int j = 0; j < strlen(str); j++)
		{
			if (j == num-1)
				continue;
			else
			{
				str1[k] = str[j];
				k++;
			}
		}
		printf("%s\n", str1);
	}
	return 0;
}