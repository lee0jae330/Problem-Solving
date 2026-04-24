#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int tree[100001];
int arr[100001];
int compare(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y)
		return 1;
	else if (x > y)
		return -1;
	return 0;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &tree[i]);
	qsort(tree, N, sizeof(int), compare);
	for (int i = 0; i < N; i++)
		arr[i] = i + 1 + tree[i];
	qsort(arr, N, sizeof(int), compare);
	printf("%d\n", arr[0] + 1);
	return 0;
}
