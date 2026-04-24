#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 500001
typedef struct a
{
	char name[22];
}NAME;
NAME arr[SIZE], arr1[SIZE];
int Bsearch(NAME* tmp, int len, char* str)
{
	int first = 0;
	int last = len - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (strcmp(str, tmp[mid].name)==0)
			return 1;
		else if (strcmp(str, tmp[mid].name) <0)
			last = mid - 1;
		else if(strcmp(str, tmp[mid].name) >0)
			first = mid + 1;
	}
	return 0;
}
int compare(const void* a, const void* b)
{
	NAME* x, * y;
	x = (NAME*)a;
	y = (NAME*)b;
	return strcmp(x->name, y->name);
}
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", arr[i].name);
	for (int i = 0; i < M; i++)
		scanf("%s", arr1[i].name);
	qsort(arr1, M, sizeof(arr1[0]), compare);
	qsort(arr, N, sizeof(arr[0]), compare);
	int temp = -1;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		temp = Bsearch(arr1, M, arr[i].name);
		if (temp == 1)
		{		
			count++;
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < N; i++)
	{
		temp = Bsearch(arr1, M, arr[i].name);
		if (temp == 1)
		{
			printf("%s\n", arr[i].name);
		}
	}
	return 0;
}
