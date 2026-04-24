#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int time, minute;
	scanf("%d %d", &time, &minute);
	int a_time, a_minute;
	if (minute - 45 >= 0)
	{
		a_time = time;
		a_minute = minute - 45;
	}
	else
	{
		if (time == 0)
			a_time = 23;
		else
			a_time = time - 1;
		a_minute = minute + 15;
	}
	printf("%d %d\n", a_time, a_minute);
	return 0;
}