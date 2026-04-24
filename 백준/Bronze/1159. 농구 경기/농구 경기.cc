#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int alphabet[26] = { 0, };
	int N;
	char name[150][100];
	char alpha[27] = "abcdefghijklmnopqrstuvwxyz";
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s",name[i]);
		getchar();
	}
	for (int i = 0; i < N; i++)
	{
		if (name[i][0] == 'a')
			alphabet[0]++;
		else if (name[i][0] == 'b')
			alphabet[1]++;
		else if (name[i][0] == 'c')
			alphabet[2]++;
		else if (name[i][0] == 'd')
			alphabet[3]++;
		else if (name[i][0] == 'e')
			alphabet[4]++;
		else if (name[i][0] == 'f')
			alphabet[5]++;
		else if (name[i][0] == 'g')
			alphabet[6]++;
		else if (name[i][0] == 'h')
			alphabet[7]++;
		else if (name[i][0] == 'i')
			alphabet[8]++;
		else if (name[i][0] == 'j')
			alphabet[9]++;
		else if (name[i][0] == 'k')
			alphabet[10]++;
		else if (name[i][0] == 'l')
			alphabet[11]++;
		else if (name[i][0] == 'm')
			alphabet[12]++;
		else if (name[i][0] == 'n')
			alphabet[13]++;
		else if (name[i][0] == 'o')
			alphabet[14]++;
		else if (name[i][0] == 'p')
			alphabet[15]++;
		else if (name[i][0] == 'q')
			alphabet[16]++;
		else if (name[i][0] == 'r')
			alphabet[17]++;
		else if (name[i][0] == 's')
			alphabet[18]++;
		else if (name[i][0] == 't')
			alphabet[19]++;
		else if (name[i][0] == 'u')
			alphabet[20]++;
		else if (name[i][0] == 'v')
			alphabet[21]++;
		else if (name[i][0] == 'w')
			alphabet[22]++;
		else if (name[i][0] == 'x')
			alphabet[23]++;
		else if (name[i][0] == 'y')
			alphabet[24]++;
		else
			alphabet[25]++;
	}
	int count = 0;
	int arr[26] = { 0, };
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] >= 5)
		{
			count++;
			arr[i] = 1;
		}
	}
	if (count > 0)
	{
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] == 1)
			{
				printf("%c", alpha[i]);
			}
		}
	}
	else
		printf("PREDAJA\n");
	return 0;
}