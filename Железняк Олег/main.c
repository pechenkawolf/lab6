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

    printf("\n\n������� ���������� �����: ");
    scanf("%d", &n);

    printf("������� ��� �������� �����: ");
    scanf("%s", fileName);

    res = readFile(fileName, n);

    printf("������� ��� ��������� �����: ");
    scanf("%s", fileName);

    writeFile("output.txt", res, n);

    free(res);
    return 0;
}
