#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10002
int arr[SIZE] = { 0, };
int compare(const void* a, const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;
	if (x < y)
		return 1;
	else if (x > y)
		return -1;
	return 0;
}

int main(void)
{
	arr[0] = 1,arr[1]=1;
	for (int i = 2; i < SIZE /i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j += i)
		{
			if (j % i == 0)
				arr[j] = 1;
		}
	}
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		int arr1[1000] = { 0, };
		int index = 0;
		int num;
		scanf("%d", &num);
		getchar();
		for (int j = 0; j < num+1; j++)
		{
			if (arr[j] == 0)
			{
				arr1[index] = j;
				if (num - j < j)
					break;
				index++;
			}
		}
		int nn;
		for (int j = 0; j <= index; j++)
		{
			nn = num - arr1[j];
			if (arr[nn] == 1)
				arr1[j] = 0;
		}
	
		int gap[1000];
		for (int j = 0; j < 1000; j++)
			gap[j] = -1;
		int idid[1000] = { 0, };
		int ii = 0;
		for (int j = 0; j <= index; j++)
		{
			if (arr1[j] == 0)
				continue;
			else
			{
				gap[ii] = num - arr1[j] - arr1[j];
				idid[ii] = j;
				ii++;
			}
		}
		int sol = 0;
		int n1, n2;
		if (ii==1)
		{
			n1 = arr1[idid[ii-1]];
			n2 = num - n1;
			printf("%d %d\n", n1, n2);
		}
		else if(ii>1)
		{
			for (int j = 0; j < ii; j++)
			{
				if (gap[j] > gap[j + 1])
					sol = j + 1;
			}
			n1= arr1[idid[sol-1]];
			n2 = num - n1;
			printf("%d %d\n", n1, n2);
		}
	}
	return 0;
}