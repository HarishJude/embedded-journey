#include <stdio.h>

int main(void)
{

    for (int celsius = 0; celsius <= 100; celsius += 10)
    {
        double fahrenheit = (9.0 / 5.0) * celsius + 32.0;
        printf("%7d  %6.1f\n", celsius, fahrenheit);
    }
}