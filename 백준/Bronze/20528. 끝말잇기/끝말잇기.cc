#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int n;
	int count = 0;
	scanf("%d", &n);
	char str[100][101];
	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);
	char fst = str[0][0];
	char lst = str[0][strlen(str[0])-1];
	for (int i = 1; i < n; i++)
	{
		if (str[i][0] == fst && str[i][strlen(str[i])-1])
			continue;
		else
			count++;
	}
	if (count == 0)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}