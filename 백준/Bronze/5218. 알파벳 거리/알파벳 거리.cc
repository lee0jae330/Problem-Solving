#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	getchar();
	char str1[30], str2[30];
	int arr[30] = { 0, };
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str1);
		getchar();
		scanf("%s", str2);
		getchar();
		for (int j = 0; j < strlen(str1); j++)
		{
			if (str1[j] <= str2[j])
				arr[j] = str2[j] - str1[j];
			else
				arr[j] = 26 + str2[j] - str1[j];
		}
		printf("Distances: ");
		for (int j = 0; j < strlen(str1); j++)
			printf("%d ", arr[j]);
		printf("\n");
	}
	return 0;
}