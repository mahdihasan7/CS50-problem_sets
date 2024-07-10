#include <stdio.h>

int is_triangle(int a, int b, int c);
int main(void)
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (is_triangle(a, b, c))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
    
}

int is_triangle(int a, int b, int c)
{
    if (a + b > c && b + c > a && c + a > b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}