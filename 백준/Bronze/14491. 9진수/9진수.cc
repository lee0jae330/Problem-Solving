#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int num,i=0;
	char nine[6]="";
	scanf("%d", &num);
	while (num >= 9)
	{
		nine[i] = num % 9;
		num /= 9;
		i++;
	}
	nine[i] = num;
	for (; i >= 0; i--)
	{
		if (nine[i] < 10)
			printf("%c", nine[i] + 48);
		else
			printf("%c", nine[i] + 55);
	}
	printf("\n");
	return 0;

}