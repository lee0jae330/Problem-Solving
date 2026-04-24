#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[51][51] = { 0, };
int spread[51][51] = { 0, };
int air_x[2];
int air_y[2];

int main(void)
{
	int R, C, T;
	int index = 0;
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1)
			{
				air_x[index] = i;
				air_y[index] = j;
				index++;
			}
		}

	}
	int time = 0;
	int count = 0;
	while (time != T)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				spread[i][j] = arr[i][j] / 5;
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int count = 0;
				if (i == 0)
				{
					if (j + 1 < C)
					{
						arr[i][j + 1] += spread[i][j];
						count++;
					}
					if (j - 1 >= 0)
					{
						arr[i][j - 1] += spread[i][j];
						count++;
					}
					arr[i + 1][j] += spread[i][j];
					count++;
					arr[i][j] = arr[i][j] - spread[i][j] *count;
				}
				else if (i == R - 1)
				{
					if (j + 1 < C)
					{
						arr[i][j + 1] += spread[i][j];
						count++;
					}
					if (j - 1 >= 0)
					{
						arr[i][j - 1] += spread[i][j];
						count++;
					}
					arr[i - 1][j] += spread[i][j];
					count++;
					arr[i][j] -= spread[i][j] * count;
				}
				else if (j == 0)
				{
					if (i == 0 || i == R - 1)
						continue;
					else 
					{
						if (arr[i + 1][j] == -1)
							count = 2;
						else
						{
							arr[i + 1][j] += spread[i][j];
							count = 3;
						}
						arr[i - 1][j] += spread[i][j];
						arr[i][j + 1] += spread[i][j];
						arr[i][j] -= spread[i][j] * count;
					}
				}
				else if (j == C - 1)
				{
					if (i == 0 || i == R - 1)
						continue;
					count = 3;
					arr[i - 1][j] += spread[i][j];
					arr[i + 1][j] += spread[i][j];
					arr[i][j - 1] += spread[i][j];
					arr[i][j] -= spread[i][j] * count;
				}
				else
				{
					if (arr[i][j - 1] == -1)
						count = 3;
					else
					{
						count = 4;
						arr[i][j - 1] += spread[i][j];
					}
					arr[i][j + 1] += spread[i][j];
					arr[i - 1][j] += spread[i][j];
					arr[i + 1][j] += spread[i][j];
					arr[i][j] -= spread[i][j] * count;
				}
			}
		}

		int tmp = arr[0][0];
		for (int i = 1; i < C; i++)
		{
			arr[0][i - 1] = arr[0][i];
		}
		for (int i = air_x[0] - 1; i > 0; i--)
		{
			if (i + 1 == air_x[0])
				continue;
			arr[i + 1][0] = arr[i][0];
		}
		arr[1][0] = tmp;
		tmp = arr[air_x[0]][C - 1];
		for (int i = C-1; i >= 0; i--)
		{
			if (i == C - 1)
				continue;
			else
			{
				if (i == 0)
					arr[air_x[0]][i + 1] = 0;
				else
					arr[air_x[0]][i + 1] = arr[air_x[0]][i];
			}
		}

		for (int i = 1; i < air_x[0]; i++)
		{
			arr[i - 1][C - 1] = arr[i][C - 1];
		}
		arr[air_x[0]-1][C-1] = tmp;

		tmp = arr[air_x[1]][C - 1];
		for (int i = C - 2; i >= 0; i--)
		{
			if (i == 0)
				arr[air_x[1]][i + 1] = 0;
			else
				arr[air_x[1]][i + 1] = arr[air_x[1]][i];
		}
		int tmp2 = arr[R - 1][C - 1];

		for (int i = R - 2; i > air_x[1]; i--)
		{
			arr[i + 1][C - 1] = arr[i][C-1];
		}
		arr[air_x[1] + 1][C - 1] = tmp;
		
		tmp = arr[R - 1][0];
		for (int i = 1; i < C; i++)
		{
			arr[R - 1][i - 1] = arr[R - 1][i];
		}
		arr[R - 1][C - 2] = tmp2;
		for (int i = air_x[1] + 1; i < R; i++)
		{
				arr[i - 1][0] = arr[i][0];
		}
		arr[air_x[1]][0] = -1;
		arr[R - 2][0] = tmp;

		time++;
	}


	int sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			sum += arr[i][j];
	}
	printf("%d\n", sum+2);
	return 0;
}