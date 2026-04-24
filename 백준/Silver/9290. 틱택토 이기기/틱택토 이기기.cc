#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N;
	char ttt[3][4];
	char namgyu;
	int num = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%s", ttt[j]);
		getchar();
		scanf("%c", &namgyu);
		int arr[3][3] = { 0, }; //o면 2,x면3,- 면 0;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (ttt[j][k] == 'o')
					arr[j][k] += 2;
				else if (ttt[j][k] == 'x')
					arr[j][k] += 3;
				else
					continue;
			}
		}
		int r1, r2, r3;
		r1 = arr[0][0] + arr[1][0] + arr[2][0];
		r2 = arr[0][1] + arr[1][1] + arr[2][1];
		r3 = arr[0][2] + arr[1][2] + arr[2][2];
		int col1, col2, col3;
		col1 = arr[0][0] + arr[0][1] + arr[0][2];
		col2 = arr[1][0] + arr[1][1] + arr[1][2];
		col3 = arr[2][0] + arr[2][1] + arr[2][2];
		int cross1, cross2;
		cross1 = arr[0][0] + arr[1][1] + arr[2][2];
		cross2 = arr[0][2] + arr[1][1] + arr[2][0];
		int x_index, y_index;
		if (namgyu == 'x')
		{
			if (r1 == 6||r2==6||r3==6)
			{
				if (r1 == 6)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][0] == 0)
						{
							x_index = 0;
							y_index = j;
						}
					}
				}
				else if (r2 == 6)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][1] == 0)
						{
							x_index = 1;
							y_index = j;
						}
					}
				}
				else
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][2] == 0)
						{
							x_index = 2;
							y_index = j;
						}
					}
				}

			}
			else if (col1 == 6 || col2 == 6 || col3 == 6)
			{
				if (col1 == 6)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[0][j] == 0)
						{
							x_index = j;
							y_index = 0;
						}
					}
				}
				else if (col2 == 6)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[1][j] == 0)
						{
							x_index = j;
							y_index = 1;
						}
					}
				}
				else
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[2][j] == 0)
						{
							x_index = j;
							y_index = 2;
						}
					}
				}
			}
			else
			{
				if (cross1 == 6)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][j] == 0)
						{
							x_index = j;
							y_index = j;
						}
					}
				}
				else
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][2-j] == 0)
						{
							x_index = 2-j;
							y_index = j;
						}
					}
				}
			}
			ttt[y_index][x_index] = 'x';
			printf("Case %d:\n", num);
			for (int j = 0; j < 3; j++)
				printf("%s\n", ttt[j]);
		}
		else
		{
			if (r1 == 4 || r2 == 4 || r3 == 4)
			{
				if (r1 == 4)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][0] == 0)
						{
							x_index = 0;
							y_index = j;
						}
					}
				}
				else if (r2 == 4)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][1] == 0)
						{
							x_index = 1;
							y_index = j;
						}
					}
				}
				else
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][2] == 0)
						{
							x_index = 2;
							y_index = j;
						}
					}
				}

			}
			else if (col1 == 4 || col2 == 4 || col3 == 4)
			{
				if (col1 == 4)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[0][j] == 0)
						{
							x_index = j;
							y_index = 0;
						}
					}
				}
				else if (col2 == 4)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[1][j] == 0)
						{
							x_index = j;
							y_index = 1;
						}
					}
				}
				else
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[2][j] == 0)
						{
							x_index = j;
							y_index = 2;
						}
					}
				}
			}
			else
			{
				if (cross1 == 4)
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][j] == 0)
						{
							x_index = j;
							y_index = j;
						}
					}
				}
				else
				{
					for (int j = 0; j < 3; j++)
					{
						if (arr[j][2 - j] == 0)
						{
							x_index = 2 - j;
							y_index = j;
						}
					}
				}
			}
			ttt[y_index][x_index] = 'o';
			printf("Case %d:\n", num);
			for (int j = 0; j < 3; j++)
				printf("%s\n", ttt[j]);
		}
		num++;
	}
	return 0;
}