#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "my_str.h"

int my_insert (char *str, int k, char c)
{
    if (str == NULL)
    {
        return 1;
    }
    if (strlen(str) >= N - 1)
    {
        return 2;
    }
    if (strlen(str) < k)
    {
        return 3;
    }
    char *beg = str + k;
    char *end = str + strlen(str) + 1;
    for ( ; beg < end; --end)
    {
        *end = *(end - 1);
    }
    *beg = c;
    return 0;
}

