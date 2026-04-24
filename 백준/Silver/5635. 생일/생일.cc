#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct birth
{
	char name[17];
	int day;
	int month;
	int year;
}BD;
int compare(const void* a, const void* b)
{
	BD* x, * y;
	x = (BD*)a;
	y = (BD*)b;
	if (x->year == y->year)
	{
		if (x->month == y->month)
		{
			if (x->day < y->day)
				return -1;
			else
				return 1;
		}
		else if (x->month < y->month)
			return -1;
		else
			return 1;
	}
	else if (x->year < y->year)
		return -1;
	else 
		return 1;
	return 0;
}
int main(void)
{
	BD arr[100];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s %d %d %d", arr[i].name, &arr[i].day, &arr[i].month, &arr[i].year);
	qsort(arr, N, sizeof(arr[0]), compare);
	printf("%s\n%s\n", arr[N-1].name, arr[0].name);
	return 0;
}
