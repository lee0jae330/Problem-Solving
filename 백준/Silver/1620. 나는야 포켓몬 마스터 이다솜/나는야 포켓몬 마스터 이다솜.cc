#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct dict
{
	char name[22];
	int num;
}DICT;

DICT arr1[100001];
DICT arr2[100001];

int compare1(const void* a, const void* b)
{
	DICT* x = (DICT*)a;
	DICT* y = (DICT*)b;
	return strcmp(x->name, y->name);
}

int compare2(const void* a, const void* b)
{
	DICT* x = (DICT*)a;
	DICT* y = (DICT*)b;
	if (x->num < y->num)
		return -1;
	else if (x->num > y->num)
		return 1;
	return 0;
}

int B_search_alpha(DICT* x, int len, char* str)
{
	int start = 0;
	int end = len - 1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (!strcmp(x[mid].name, str))
			return x[mid].num;
		else if (strcmp(x[mid].name, str) < 0)
			start = mid + 1;
		else
			end = mid - 1;
	}
}

int B_search_digit(DICT* x, int len, int target)
{
	int start = 0;
	int end = len - 1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (x[mid].num == target)
			return mid;
		else if (x[mid].num < target)
			start = mid + 1;
		else
			end = mid - 1;
	}
}

int main(void)
{
	int N, M;
	char tmp[22];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr1[i].name);
		strcpy(arr2[i].name, arr1[i].name);
		arr1[i].num = i + 1;
		arr2[i].num = i + 1;
	}
	qsort(arr1, N, sizeof(arr1[0]), compare1); //알파벳
	qsort(arr2, N, sizeof(arr2[0]), compare2);//숫자
	for (int i = 0; i < M; i++)
	{
		scanf("%s", tmp);
		if (isdigit(tmp[0]))
		{
			int sol = atoi(tmp);
			printf("%s\n", arr2[B_search_digit(arr2, N, sol)].name);
		}
		else
		{
			printf("%d\n", B_search_alpha(arr1, N, tmp));
		}
	}
	return 0;
}