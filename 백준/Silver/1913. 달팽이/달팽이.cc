#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[999][999] = { 0, };
int main(void) {
    int num, x = 0, y = 0;
    int size, sign = 1;
    int find;
    scanf("%d %d", &size,&find);
    num = size * size;
    for (int i = 0; i < size; i++)
    {
        arr[y][x] = num--;
        y += sign;
    }
    y -= sign;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            x += sign;
           arr[y][x] = num--;
        }
        sign *= -1;
        for (int j = 0; j < i; j++)
        {
            y += sign;
            arr[y][x] = num--;
        }
    }
    int y_index=-1, x_index=-1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == find)
            {
                y_index = i + 1;
                x_index = j + 1;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("%d %d\n", y_index, x_index);
    return 0;
}