#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "my_str.h"

int entry(char *str)
{
    if (str == NULL)
    {
        return 1;
    }
    printf("¬ведите строку:\n");
    char s = ' ';
    int n = 0;
    while (s != '\n')
    {
        scanf("%c", &s);
        *(str + n) = s;
        ++n;
        if (n > N)
        {
            return 1;
        }
    }
    --n;
    *(str + n) = '\0';
    return 0;
}

