#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    int cnt = 2;
    for (int i = 0; i < N; i++)
        cnt += cnt - 1;
    printf("%d\n", cnt * cnt);
    return 0;
}