#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "lab6.h"

void* readFile(const char *fileName, size_t n)
{
    int i;
    FILE *in = fopen(fileName, "r");
    char (*res)[STR_LEN] = malloc(sizeof(char[STR_LEN])*n);

    for(i = 0; i < n; ++i)
        fscanf(in, "%s", res[i]);

    fclose(in);
    return res;
}

char* shorten(const char *s)
{
    char f, l;
    int i, len = 0;

    for(i = 0; s[i] != '\0'; ++i)
        ++len;

    f = s[0];
    l = s[i - 1];

    if(len > 10)
    {
        int i;
        char *res, sLen[4];

        itoa(len - 2, sLen, 10);
        res = malloc(sizeof(char)*6);

        res[0] = f;

        for(i = 1; sLen[i - 1] != '\0'; ++i)
            res[i] = sLen[i - 1];

        res[i] = l;
        res[i + 1] = '\0';

        return res;
    }

    return NULL;
}

void writeFile(const char *fileName, char (*res)[STR_LEN], size_t n)
{
    int i;
    FILE *out = fopen(fileName, "w");

    for(i = 0; i < n; ++i)
    {
        char *short_str = shorten(res[i]);

        if(short_str)
            fprintf(out, "%s\n", short_str);
        else
            fprintf(out, "%s\n", res[i]);
    }

    fclose(out);
}

void testShorten()
{
    int i;
    const int n = 5;
    char *in[] = { "localization", "internationalization", "apple", "tree", "application" };
    char *out[] = { "l10n", "i18n", "apple", "tree", "a9n" };

    for(i = 0; i < n; ++i)
    {
        char *tmp = shorten(in[i]);

        if(tmp == NULL)
        {
            if(strcmp(in[i], out[i]) != 0)
            {
                printf("Test #%d failed!\n", i);
                return;
            }
        }
        else
        {
            if(strcmp(tmp, out[i]) != 0)
            {
                printf("Test #%d failed!\n", i);
                return;
            }

            free(tmp);
        }
    }

    printf("All tests are successfully passed!\n");
}
