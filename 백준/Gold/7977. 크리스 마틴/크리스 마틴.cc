#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[4];

int main(void) {
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		char c;
		scanf("%c", &c);
		if (c == 'A')
			arr[0]++;
		else if (c == 'C')
			arr[1]++;
		else if (c == 'G')
			arr[2]++;
		else
			arr[3]++;
	}
	int idx=0;
	int mn = arr[0];
	for (int i = 1; i < 4; i++) {
		if (arr[i] < mn) {
			idx = i;
			mn = arr[i];
		}
	}
	printf("%d\n", mn);
	char ch;
	switch (idx) {
	case 0:
		ch = 'A';
		break;
	case 1:
		ch = 'C';
		break;
	case 2:
		ch = 'G';
		break;
	default:
		ch = 'T';
	}
	for (int i = 0; i < N; i++)
		printf("%c", ch);
	return 0;
}
