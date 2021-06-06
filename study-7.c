#include <stdio.h>
#include <stdlib.h>

int counter(int n)
{
    static int result=0;

    result = result + n;

    return result;
}

int main(void)
{
    int i;

    for (i = 0; i < 5; i++)
        printf("counter(%d)=%d\n", i, counter(i));
    for (i = 0; i > -5; i--)
        printf("counter(%d)=%d\n", i, counter(i));

    return EXIT_SUCCESS;
}