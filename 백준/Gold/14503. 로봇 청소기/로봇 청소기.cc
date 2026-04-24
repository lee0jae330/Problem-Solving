#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[52][52];
int count = 0;
int can_move;
int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };
void robot(int cur_r, int cur_c, int cur_dir)
{
	int r = cur_r, c = cur_c, dir = cur_dir;
	arr[r][c] = -1;
	count++;
	while (1)
	{
		can_move = 0;
		for (int i = 0; i < 4;i++)
		{
			if (!arr[r + x[i]][c + y[i]])
			{
				can_move++;
				break;
			}
		}
		if (can_move==1)
		{
			if (dir == 0)
			{
				if (arr[r][c - 1] == 0)
				{
					dir = 3;
					c--;
					count++;
					arr[r][c] = -1;
				}
				else
				{
					dir = 3;
				}
			}
			else if (dir == 1)
			{
				if (arr[r - 1][c] == 0)
				{
					dir = 0;
					r--;
					arr[r][c] = -1;
					count++;
				}
				else
				{
					dir = 0;

				}
			}
			else if (dir == 2)
			{
				if (arr[r][c + 1] == 0)
				{
					dir = 1;
					c++;
					arr[r][c] = -1;
					count++;
				}
				else
				{
					dir = 1;

				}
			}
			else
			{
				if (arr[r + 1][c] == 0)
				{
					dir = 2;
					r++;
					arr[r][c] = -1;
					count++;
				}
				else
				{
					dir = 2;

				}
			}
		}
		else
		{
			int input = 0;
			if (dir == 0)
			{
				if (arr[r + 1][c] != 1)
					r++;
				else
					input = 1;
				if (input)
					break;
			}
			else if (dir == 1)
			{
				if (arr[r][c-1] != 1)
					c--;
				else
					input = 1;
				if (input)
					break;
			}
			else if (dir == 2)
			{
				if (arr[r-1][c] != 1)
					r--;
				else
					input = 1;
				if (input)
					break;
			}
			else
			{
				if (arr[r][c + 1] != 1)
					c++;
				else
					input = 1;
				if (input)
					break;
			}
		}
		
	}
}
// 0 북 1 동 2 남 3 서
// 0 빈칸 1 벽 -1 청소한 곳

int main(void)
{
	int r, c;
	scanf("%d %d", &r, &c);
	int cur_r, cur_c, cur_dir;
	scanf("%d %d %d", &cur_r, &cur_c, &cur_dir);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	robot(cur_r, cur_c, cur_dir);
	printf("%d\n", count);
	return 0;
}