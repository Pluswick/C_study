#include <stdio.h>
#include <stdlib.h>

int strlen_arr(char s[])
{
    int i = 0, length = 0;
    for (i = 0; s[i] != '\0'; i++)
        length++;
    return length;

}

int strlen_ptr(char* s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int main(void)
{
    char* str1 = "5 Pointers and arrays";
    char str2[] = { 'H', 'e', 'l', 'l', 'o', '!', '\0' };

    printf("str1=%s\n", str1);
    printf("strlen_arr(str1)=%d\n", strlen_arr(str1));
    printf("strlen_ptr(str1)=%d\n", strlen_ptr(str1));

    printf("str2=%s\n", str2);
    printf("strlen_arr(str2)=%d\n", strlen_arr(str2));
    printf("strlen_ptr(str2)=%d\n", strlen_ptr(str2));

    return EXIT_SUCCESS;
}