#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
	char name1[5];
	char name2[5];
	fgets(name1, 5, stdin);
	name1[strlen(name1) - 1] = '\0';
	fgets(name2, 5, stdin);
	name2[strlen(name2) - 1] = '\0';
	char num1[5], num2[5];
	int j = 0;
	for (int i = strlen(name1) - 1; i >= 0; i--)
	{
		num1[j] = name1[i];
		j++;
	}
	j = 0;
	for (int i = strlen(name2) - 1; i >= 0; i--)
	{
		num2[j] = name2[i];
		j++;
	}
	int n1, n2;
	n1 = atoi(num1);
	n2 = atoi(num2);
	if (n1 > n2)
		printf("%d\n", n1);
	else
		printf("%d\n", n2);
	
	return 0;
}