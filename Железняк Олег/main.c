#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "lab6.h"

int main()
{
    setlocale(LC_CTYPE, "russian");

    testShorten();

    int n;
    char fileName[STR_LEN];
    char (*res)[STR_LEN];

    printf("\n\nВведите количество строк: ");
    scanf("%d", &n);

    printf("Введите имя входного файла: ");
    scanf("%s", fileName);

    res = readFile(fileName, n);

    printf("Введите имя выходного файла: ");
    scanf("%s", fileName);

    writeFile(fileName, res, n);

    free(res);
    return 0;
}
