#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct number
{
	int num;
	int count = 1;
	int order;
}NUMBER;
NUMBER arr[1000];
int compare(const void* a, const void* b)
{
	NUMBER* x, * y;
	x = (NUMBER*)a;
	y = (NUMBER*)b;
	if (x->count == y->count)
	{
		if (x->order < y->order)
			return -1;
		else if (x->order > y->order)
			return 1;

	}
	else if (x->count < y->count)
		return 1;
	else
		return -1;
}
int main(void)
{
	int N, C;
	scanf("%d %d", &N, &C);
	int index = 0;
	scanf("%d", &arr[index].num);
	arr[index].order = index;
	for (int i = 1; i < N; i++)
	{
		int tmp;
		int input = 0;
		scanf("%d", &tmp);
		for (int j = 0; j <= index; j++)
		{
			if (tmp == arr[j].num)
			{
				arr[j].count++;
				input = 1;
				break;
			}
		}
		if (input == 0)
		{
			index++;
			arr[index].num = tmp;
			arr[index].order = index;
		}
	}
	qsort(arr, index + 1, sizeof(arr[0]), compare);
	for (int i = 0; i < index+1; i++)
	{
		for (int j = 0; j < arr[i].count; j++)
			printf("%d ", arr[i].num);
	}
	printf("\n");
	return 0;
}