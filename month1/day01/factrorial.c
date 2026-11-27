#include <stdio.h>

unsigned long factorial(int n)
{
    unsigned long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int main(void)
{
    for (int j = 0; j <= 10; j++)
    {
        printf("%d ! = %lu\n ", j, factorial(j));
    }

    printf("\nTesting larger inputs:\n");
    printf("20! = %lu\n", factorial(20));
    printf("25! = %lu\n", factorial(25));

    return 0;
}