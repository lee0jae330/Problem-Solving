#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[100000];
int compare(const void* a, const void* b)
{
	char x = *(char*)a;
	char y = *(char*)b;
	if (x < y)
		return 1;
	else if (x > y)
		return -1;
	return 0;
}
int main(void)
{
	scanf("%s", str);
	int zero = 0;
	int sum = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '0')
			zero++;
		sum += (str[i] - '0');
	}
	if (zero == 0 || sum % 3 != 0)
		printf("-1");
	else if(zero!=0&&sum%3==0)
	{
		qsort(str, strlen(str), sizeof(char), compare);
		printf("%s\n", str);
	}
	return 0;
}