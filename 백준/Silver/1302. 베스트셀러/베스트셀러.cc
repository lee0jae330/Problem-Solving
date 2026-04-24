#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct book 
{
	char name[52];
	int num = 1;
}BOOK;
BOOK arr[1000];
int compare(const void* a, const void* b)
{
	BOOK* x, * y;
	x = (BOOK*)a;
	y = (BOOK*)b;
	if (x->num == y->num)
	{
		return strcmp(x->name, y->name);
	}
	else if (x->num < y->num)
		return 1;
	else
		return -1;
		
}
int main(void)
{
	int N;
	char str[52];
	int index = 0;
	scanf("%d", &N);
	scanf("%s", arr[index].name);
	for (int i = 1; i < N; i++)
	{
		int input = 0;
		scanf("%s", str);
		for (int j = 0; j <= index; j++)
		{
			if (strcmp(str, arr[j].name) == 0)
			{
				arr[j].num++;
				input = 1;
				break;
			}
		}
		if (input == 0)
		{
			index++;
			strcpy(arr[index].name, str);
		}
	}
	qsort(arr, index+1, sizeof(arr[0]), compare);
	printf("%s\n", arr[0].name);
	return 0;
}