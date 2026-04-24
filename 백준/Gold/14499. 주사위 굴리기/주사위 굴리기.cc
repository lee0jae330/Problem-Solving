#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[22][22];
int dice[2][4] = { 0, };

int main(void)
{
	int N, M, x, y, num;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &num);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		
		}
	}
	int dir;
	
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &dir);
		if (dir == 1) //동
		{
			if (y + 1 >= M)
				continue;
			else
			{
				y++;
				int tmp = dice[1][3];
				for (int j = 2; j >= 0; j--)
					dice[1][j + 1] = dice[1][j];
				dice[1][0] = tmp;
				dice[0][0] = dice[1][0];
				dice[0][2] = dice[1][2];
				printf("%d\n", dice[1][0]);
				if (!arr[x][y])
				{
					arr[x][y] = dice[0][2];
				}
				else
				{
					dice[0][2] = arr[x][y];
					dice[1][2] = dice[0][2];
					arr[x][y] = 0;
				}
			}
		}
		else if (dir == 2) //서
		{
			if (y - 1 < 0)
				continue;
			else
			{
				y--;
				int tmp = dice[1][0];
				for (int j = 0; j < 3; j++)
					dice[1][j] = dice[1][j + 1];
				dice[1][3] = tmp;
				dice[0][0] = dice[1][0];
				dice[0][2] = dice[1][2];
				printf("%d\n", dice[1][0]);
				if (!arr[x][y])
				{
					arr[x][y] = dice[0][2];
				}
				else
				{
					dice[0][2] = arr[x][y];
					dice[1][2] = dice[0][2];
					arr[x][y] = 0;
				}
			}
		}
		else if (dir == 3) //북
		{
			if (x - 1 < 0)
				continue;
			else
			{
				x--;
				int tmp = dice[0][0];
				for (int j = 0; j < 3; j++)
					dice[0][j] = dice[0][j + 1];
				dice[0][3] = tmp;
				dice[1][0] = dice[0][0];
				dice[1][2] = dice[0][2];
				printf("%d\n", dice[0][0]);
				if (!arr[x][y])
					arr[x][y] = dice[0][2];
				else
				{
					dice[0][2] = arr[x][y];
					dice[1][2] = dice[0][2];
					arr[x][y] = 0;
				}
			}
		}
		else //남
		{
			if (x + 1 >= N)
				continue;
			else
			{
				x++;
				int tmp = dice[0][3];
				for (int j = 2; j >= 0; j--)
					dice[0][j + 1] = dice[0][j];
				dice[0][0] = tmp;
				dice[1][0] = dice[0][0];
				dice[1][2] = dice[0][2];
				printf("%d\n", dice[0][0]);
				if (!arr[x][y])
					arr[x][y] = dice[0][2];
				else
				{
					dice[0][2] = arr[x][y];
					dice[1][2] = dice[0][2];
					arr[x][y] = 0;
				}
			}
		}
	}
	return 0;
}