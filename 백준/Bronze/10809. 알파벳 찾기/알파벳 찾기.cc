#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int arr[27];

int main(void)
{
	char str[102];
	scanf("%s", str);
	for (int i = 0; i < 27; i++)
		arr[i] = -1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (arr[str[i] - 'a'] == -1)
		{
			arr[str[i] - 'a'] = i;
		}
		else
			continue;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}