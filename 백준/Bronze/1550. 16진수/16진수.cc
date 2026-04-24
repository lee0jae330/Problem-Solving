#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	char str[10];
	scanf("%s", str);
	int num = 0;
	int arr[10] = { 0, };
	for (int i = strlen(str)-1; i >=0; i--)
	{
		if (str[i] == '0')
			arr[num] =0* pow(16, num);
		else if (str[i] == '1')
			arr[num] = 1 * pow(16, num);
		else if (str[i] == '2')
			arr[num] = 2 * pow(16, num);
		else if (str[i] == '3')
			arr[num] = 3 * pow(16, num);
		else if (str[i] == '4')
			arr[num] = 4 * pow(16, num);
		else if (str[i] == '5')
			arr[num] = 5 * pow(16, num);
		else if (str[i] == '6')
			arr[num] = 6 * pow(16, num);
		else if (str[i] == '7')
			arr[num] = 7 * pow(16, num);
		else if (str[i] == '8')
			arr[num] = 8 * pow(16, num);
		else if (str[i] == '9')
			arr[num] = 9 * pow(16, num);
		else if (str[i] == 'A')
			arr[num] = 10 * pow(16, num);
		else if (str[i] == 'B')
			arr[num] = 11 * pow(16, num);
		else if (str[i] == 'C')
			arr[num] = 12 * pow(16, num);
		else if (str[i] == 'D')
			arr[num] = 13 * pow(16, num);
		else if (str[i] == 'E')
			arr[num] = 14 * pow(16, num);
		else if (str[i] == 'F')
			arr[num] = 15 * pow(16, num);
		num++;
	}
	long long result = 0;
	for (int i = 0; i < strlen(str); i++)
		result += arr[i];
	printf("%lld\n", result);
	return 0;
}