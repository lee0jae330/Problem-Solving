#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	char A[100] = "";
	char B[100] = "";
	char total[10000] = "";
	char operation;
	scanf("%s", &A);
	getchar();
	scanf("%c", &operation);
	getchar();
	scanf("%s", &B);
	getchar();
	if (operation == '+')
	{
		if (strlen(A) > strlen(B))
		{
			strcpy(total, A);
			total[strlen(A) - strlen(B)] = B[0];
			printf("%s\n", total);
		}
		else if (strlen(A) < strlen(B))
		{
			strcpy(total, B);
			total[strlen(B) - strlen(A)] = A[0];
			printf("%s\n", total);
		}
		else
		{
			strcpy(total, A);
			total[strlen(A) - strlen(B)] = '2';
			printf("%s\n", total);
		}
	}
	char arr[2] = "0";
	if (operation == '*')
	{
		int tmp = (strlen(A) < strlen(B)) ? strlen(A) : strlen(B);
		if (tmp == strlen(B))
		{
			strcpy(total, A);
			for (int i = 0; i < tmp - 1; i++)
				strcat(total, arr);
			printf("%s\n", total);
		}
		else
		{
			strcpy(total, B);
			for (int i = 0; i < tmp - 1; i++)
				strcat(total, arr);
			printf("%s\n", total);
		}
	}
	return 0;
}