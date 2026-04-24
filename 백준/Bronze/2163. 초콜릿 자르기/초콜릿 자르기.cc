#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (n < m)
    {
        int a = (n - 1) + n * (m - 1);
        printf("%d\n", a);
    }
    else if (n > m)
    {
        int a = (m - 1) + m * (n - 1);
        printf("%d\n", a);
    }
    else
    {
        int a = (n - 1) + n*(n - 1);
        printf("%d\n", a);
    }
    return 0;
}