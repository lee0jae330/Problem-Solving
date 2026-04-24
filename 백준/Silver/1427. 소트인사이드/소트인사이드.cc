#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char num[11];
	scanf("%s", num);
	for (int i = 0; i < strlen(num); i++)
	{
		for (int j = 0; j < strlen(num) - 1; j++)
		{
			if (num[j] < num[j + 1])
			{
				char x = num[j];
				num[j] = num[j + 1];
				num[j + 1] = x;
			}
		}
	}
	printf("%s", num);
	return 0;
}