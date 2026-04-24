#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
	char name[13];
	int korean;
	int english;
	int math;
}STU;
STU arr[100001];
int compare(const void* a, const void* b)
{
	STU* x, * y;
	x = (STU*) a;
	y = (STU*) b;
	if (x->korean == y->korean)
	{
		if (x->english == y->english)
		{
			if (x->math == y->math)
			{
				return strcmp(x->name, y->name);
			}
			else if (x->math < y->math)
				return 1;
			else
				return -1;
		}
		else if (x->english < y->english)
			return -1;
		else
			return 1;
	}
	else if (x->korean < y->korean)
		return 1;
	else
		return -1;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s %d %d %d", arr[i].name, &arr[i].korean, &arr[i].english, &arr[i].math);
	qsort(arr, N, sizeof(arr[0]), compare);
	for (int i = 0; i < N; i++)
		printf("%s\n", arr[i].name);
	return 0;
}