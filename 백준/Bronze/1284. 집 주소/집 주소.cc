#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int a;
	int n;
	for (int i = 0;; i++)
	{
		scanf("%d", &a);
		if (a != 0)
		{
			if (a /1000 != 0)
			{
				int x = a / 1000;
				if (x == 1)
					x = 2;
				else
					x = 3;
				int y = (a % 1000) / 100;
				if (y == 0)
					y = 4;
				else if (y == 1)
					y = 2;
				else
					y = 3;
				int z = ((a % 1000) % 100) / 10;
				if (z == 0)
					z = 4;
				else if (z == 1)
					z = 2;
				else
					z = 3;
				int k = ((a % 1000) % 100) % 10;
				if (k == 0)
					k = 4;
				else if (k == 1)
					k = 2;
				else
					k = 3;
				n = x + y + z + k+3+2;
				printf("%d\n", n);

			}
			else
			{
				if (a / 100 != 0)
				{
					int x = a / 100;
					if (x == 1)
						x = 2;
					else
						x = 3;
					int y = (a % 100) / 10;
					if (y == 0)
						y = 4;
					else if (y == 1)
						y = 2;
					else
						y = 3;
					int z = (a % 100) % 10;
					if (z == 0)
						z = 4;
					else if (z == 1)
						z = 2;
					else
						z = 3;
					n = x + y + z+2+2;
					printf("%d\n", n);

				}
				else
				{
					if (a / 10 != 0)
					{
						int x = a / 10;
						if (x == 1)
							x = 2;
						else
							x = 3;
						int y = a % 10;
						if (y == 0)
							y = 4;
						else if (y == 1)
							y = 2;
						else
							y = 3;
						n = x + y+1+2;
						printf("%d\n", n);
					}
					if(a/10==0)
					{
						int x = a % 10;
						if (x == 1)
							x = 2;
						else
							x = 3;
						int n = x + 2;
						printf("%d\n", n);
					}
				}
				
				
				
				}
			}
		if(a==0)
		{
			break;	
		}
		
	}
		return 0;
}