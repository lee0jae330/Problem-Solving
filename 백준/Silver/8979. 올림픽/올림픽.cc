#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct medal
{
	int number;
	int gold;
	int silver;
	int copper;
}MEDAL;
MEDAL arr[1000];
int compare(const void* a, const void* b)
{
	MEDAL *x, *y;
	x = (MEDAL*)a;
	y = (MEDAL*)b;
	if (x->gold == y->gold)
	{
		if (x->silver == y->silver)
		{
			if (x->copper == y->copper)
			{
				return 0;
			}
			else if (x->copper < y->copper)
				return 1;
			else
				return -1;
		}
		else if (x->silver < y->silver)
			return 1;
		else
			return -1;
	}
	else if (x->gold < y->gold)
		return 1;
	else
		return -1;

}
int main(void)
{
	int nation, number;
	scanf("%d %d", &nation, &number);
	for (int i = 0; i < nation;i++)
		scanf("%d %d %d %d", &arr[i].number, &arr[i].gold, &arr[i].silver, &arr[i].copper);
	qsort(arr, nation, sizeof(arr[0]), compare);
	int index = -1;
	for (int i = 0; i < nation; i++)
	{
		if (arr[i].number == number)
		{
			if (arr[i].gold == arr[i - 1].gold && arr[i].silver == arr[i - 1].silver && arr[i].copper == arr[i - 1].copper)
			{
				for (int j = i - 1; j > 0; j--)
				{
					if (arr[i].gold == arr[j].gold && arr[i].silver == arr[j].silver && arr[i].copper == arr[j].copper)
						index = j;
				}
				printf("%d\n", index + 1);
				break;
			}
			else
			{
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}