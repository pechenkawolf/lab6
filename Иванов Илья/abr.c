#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "my_str.h"

int abbr (char *str)
{
    if (strlen(str) < 10)
    {
        return 1;
    }
    char last = *(str + strlen(str) - 1);
    int n = strlen(str) - 2;
    char *beg = str;
    while (n > 0)
    {
        ++beg;
        char c = (char) (n % 10 + '0');
        my_insert(str, 1, c);
        n /= 10;
    }
    *(beg + 1) = last;
    *(beg + 2) = '\0';
    return 0;
}
