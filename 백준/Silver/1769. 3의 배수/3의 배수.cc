#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char number[1000002];
int main(void)
{
	int count = 0;
	scanf("%s", number);
	int num=0;
	for (int i = 0; i < strlen(number); i++)
	{
		num += (number[i] - '0');
	}
	if(strlen(number)>1)
		count++;
	int result = 0;
	char tmp[10];
	while (1)
	{
		sprintf(tmp, "%d", num);
		if (strlen(tmp) == 1)
			break;
		else
		{
			num = 0;
			for (int i = 0; i < strlen(tmp); i++)
			{
				num += tmp[i] - '0';
			}
			count++;
		}
	}
	result = tmp[0] - '0';
	if (result == 0)
		printf("%d\nNO\n",count);
	if (result % 3 == 0)
		printf("%d\nYES\n", count);
	else
		printf("%d\nNO\n", count);
	return 0;
}
