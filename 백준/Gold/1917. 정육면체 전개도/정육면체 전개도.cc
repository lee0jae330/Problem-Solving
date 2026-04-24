#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

int arr[3][6][6];
vector<int>r;
vector<int>c;
char str1[4];
char str2[4];
char str3[4];
int right[3];
int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				scanf("%d", &arr[i][j][k]);
			}
		}
	}
	
	int check=0;
	for (int x = 0; x < 3; x++)
	{
		check = 0;
		for (int i = 0; i < 6; i++)
		{
			check = 0;
			for (int j = 0; j < 6; j++)
			{
				if (arr[x][i][j] == 1)
					check++;
			}
			if(check)
				r.push_back(check);
		}
		for (int j = 0; j < 6; j++)
		{
			check = 0;
			for (int i = 0; i < 6; i++)
			{
				if (arr[x][i][j] == 1)
					check++;
			}
			if (check)
				c.push_back(check);
		}
		int check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
		if (r.size() == 2)
		{
			if (c.size() == 5)
			{
				if (r[0] == 3 && r[1] == 3)
				{
					if (c[0] == 1 && c[1] == 1 && c[2] == 2 && c[3] == 1 && c[4] == 1)
					{
						right[x] = 1;
					}
				}
				
			}
		}
		else if (r.size() == 3)
		{
			if (c.size() == 4)
			{
				check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
				if (r[0]==1&&r[1]==4&&r[2]==1)
				{
					check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
					for (int i = 0; i < c.size(); i++)
					{
						if (c[i] == 1)
							check_1++;
						else if (c[i] == 2)
							check_2++;
						else if (c[i] == 3)
							check_3++;
						else if (c[i] == 4)
							check_4++;
					}
					if ((check_1 == 3 && check_3 == 1) || (check_1 == 2 && check_2 == 2))
						right[x] = 1;
				}
				else if ((r[0]==2&&r[1]==3&&r[2]==1)||(r[0]==1&&r[1]==3&&r[2]==2))
				{
					check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
					for (int i = 0; i < c.size(); i++)
					{
						if (c[i] == 1)
							check_1++;
						else if (c[i] == 2)
							check_2++;
						else if (c[i] == 3)
							check_3++;
						else if (c[i] == 4)
							check_4++;
					}
					if ((check_1 == 3 && check_3 == 1) || (check_1 == 2 && check_2 == 2))
						right[x] = 1;
				}
				else if (r[0]==2&&r[1]==2&&r[2]==2)
				{
					check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
					for (int i = 0; i < c.size(); i++)
					{
						if (c[i] == 1)
							check_1++;
						else if (c[i] == 2)
							check_2++;
						else if (c[i] == 3)
							check_3++;
						else if (c[i] == 4)
							check_4++;
					}
					if (check_1 == 2 && check_2 == 2)
						right[x] = 1;
				}
			}
		}
		else if (r.size() == 4)
		{
			if (c.size() == 3)
			{
				check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
				if (c[0] == 1 && c[1] == 4 && c[2] == 1)
				{
					check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
					for (int i = 0; i < r.size(); i++)
					{
						if (r[i] == 1)
							check_1++;
						else if (r[i] == 2)
							check_2++;
						else if (r[i] == 3)
							check_3++;
						else if (r[i] == 4)
							check_4++;
					}
					if ((check_1 == 3 && check_3 == 1) || (check_1 == 2 && check_2 == 2))
						right[x] = 1;
				}
				else if ((c[0] == 2 && c[1] == 3 && c[2] == 1) || (c[0] == 1 && c[1] == 3 && c[2] == 2))
				{
					check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
					for (int i = 0; i < r.size(); i++)
					{
						if (r[i] == 1)
							check_1++;
						else if (r[i] == 2)
							check_2++;
						else if (r[i] == 3)
							check_3++;
						else if (r[i] == 4)
							check_4++;
					}
					if ((check_1 == 3 && check_3 == 1) || (check_1 == 2 && check_2 == 2))
						right[x] = 1;
				}
				else if (c[0] == 2 && c[1] == 2 && c[2] == 2)
				{
					check_1 = 0, check_2 = 0, check_3 = 0, check_4 = 0;
					for (int i = 0; i < r.size(); i++)
					{
						if (r[i] == 1)
							check_1++;
						else if (r[i] == 2)
							check_2++;
						else if (r[i] == 3)
							check_3++;
						else if (r[i] == 4)
							check_4++;
					}
					if (check_1 == 2 && check_2 == 2)
						right[x] = 1;
				}
			}
		}
		else if (r.size() == 5)
		{
			if (c.size() == 2)
			{
				if (c[0] == 3 && c[1] == 3)
				{
					if (r[0] == 1 && r[1] == 1 && r[2] == 2 && r[3] == 1 && r[4] == 1)
						right[x] = 1;
				}
			}
		}
		r.clear();
		c.clear();
	}
	if (right[0] == 1)
		strcpy(str1, "yes");
	else
		strcpy(str1, "no");
	if (right[1] == 1)
		strcpy(str2, "yes");
	else
		strcpy(str2, "no");
	if (right[2] == 1)
		strcpy(str3, "yes");
	else
		strcpy(str3, "no");
	printf("%s\n%s\n%s\n", str1, str2, str3);
	return 0;
}