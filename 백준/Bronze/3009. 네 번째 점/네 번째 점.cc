#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int x[3];
	int y[3];
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);
	int distance,max,min;
	int count = 0;
	if (x[0] == x[1] || x[0] == x[2] || x[1] == x[2])
	{
		if (x[0] == x[1])
		{
			max = (y[0] > y[1]) ? y[0] : y[1];
			min = (y[0] < y[1]) ? y[0] : y[1];
			distance = max - min;
			if (y[2] == min)
				printf("%d %d\n", x[2], y[2] + distance);
			else
				printf("%d %d\n", x[2], y[2] - distance);
		}
		else if (x[0] == x[2])
		{
			max = (y[0] > y[2]) ? y[0] : y[2];
			min = (y[0] < y[2]) ? y[0] : y[2];
			distance = max - min;
			if (y[1] == min)
				printf("%d %d\n", x[1], y[1] + distance);
			else
				printf("%d %d\n", x[1], y[1] - distance);
		}
		else
		{
			max = (y[1] > y[2]) ? y[1] : y[2];
			min = (y[1] < y[2]) ? y[1] : y[2];
			distance = max - min;
			if (y[0] == min)
				printf("%d %d\n", x[0], y[0] + distance);
			else
				printf("%d %d\n", x[0], y[0] - distance);
		}
		count++;
	}
	if (count != 0)
		return 0;
	if (y[0] == y[1] || y[0] == y[2] || y[1] == y[2])
	{
		if (y[0] == y[1])
		{
			max = (x[0] > x[1]) ? x[0] : x[1];
			min= (x[0] < x[1]) ? x[0] : x[1];
			distance = max - min;
			if (x[2] == min)
				printf("%d %d\n", x[2] + distance, y[2]);
			else
				printf("%d %d\n", x[2] - distance, y[2]);
		}
		else if (y[0] == y[2])
		{
			max = (x[0] > x[2]) ? x[0] : x[2];
			min = (x[0] < x[2]) ? x[0] : x[2];
			distance = max - min;
			if (x[1] == min)
				printf("%d %d\n", x[1] + distance, y[1]);
			else
				printf("%d %d\n", x[1] - distance, y[1]);
		}
		else
		{
			max = (x[1] > x[2]) ? x[1] : x[2];
			min = (x[1] < x[2]) ? x[1] : x[2];
			distance = max - min;
			if (x[0] == min)
				printf("%d %d\n", x[0] + distance, y[0]);
			else
				printf("%d %d\n", x[0] - distance, y[0]);
		}
	}
	return 0;
}