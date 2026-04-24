#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdio.h>
int arr[2000001];
void firework()
{
    int N, C;
    scanf("%d %d", &N, &C);
    int i;
    int cnt = 0;
    int num;
    int temp;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num);
        temp = num;
        if (!arr[num])
        {
            while (1)
            {
                if (num > C)
                    break;
                else
                {
                    arr[num] = 1;
                    num += temp;
                }
            }
        }
    }
    for (i = 1; i <= C; i++)
        if (arr[i])
            cnt++;
    printf("%d", cnt);
}
int main()
{
    firework();
}