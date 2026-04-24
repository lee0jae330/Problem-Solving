#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct aa
{
	char name[12];
	double length;
	int number;
}Student;
int compare(const void* a, const void* b)
{
	Student* x, * y;
	x = (Student*)a;
	y = (Student*)b;
	if (x->length == y->length)
	{
		if (x->number < y->number)
			return -1;
		else
			return 1;
	}
	else if (x->length < y->length)
		return 1;
	else
		return -1;

}
int main(void)
{
	Student arr[51];
	int N;
	while (1)
	{
		scanf("%d", &N);
		getchar();
		if (N == 0)
			return 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%s %lf", arr[i].name, &arr[i].length);
			arr[i].number = i + 1;
		}
		qsort(arr, N, sizeof(arr[0]), compare);
		int count = 0;
		for (int i = 1; i < N; i++)
		{
			if (arr[0].length == arr[i].length)
				count++;
		}
		if (count == 0)
			printf("%s\n", arr[0].name);
		else
		{
			for (int i = 0; i < count + 1; i++)
				printf("%s ", arr[i].name);
			printf("\n");
		}
	}
	return 0;
}