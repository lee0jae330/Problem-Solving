#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int arr[8];
	for(int i=0;i<8;i++)
		scanf("%d", &arr[i]);
	int count = 0;
	int j = 8;
	for (int i = 0; i < 8; i++)
	{
		if (arr[i] == i + 1)
			count++;
		if (arr[i] == j)
			count--;
		j--;
	}
	if (count == 8)
		printf("ascending\n");
	else if (count == -8)
		printf("descending\n");
	else
		printf("mixed\n");
	return 0;
}