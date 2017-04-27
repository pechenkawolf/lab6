#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "my_str.h"

int main()
{
    setlocale(LC_CTYPE, "Rus");
    int n = 0;
    char fname[15];
    printf("������� �������� �����: (������������� string.txt)\n");
    scanf_s("%s", &fname);
    printf("������� ���������� �����.\n");
    scanf("%d", &n);
    FILE *f = fopen(fname, "r");
    if (f == NULL)
    {
        printf("Error. ���� �� ������� �������.\n");
        return 0;
    }
    FILE *fans = fopen("answer.txt", "r");
    if (fans == NULL)
    {
        printf("Error. ���� �� ������� �������.\n");
        return 0;
    }

    int i;
    for (i = 0; i < n; ++i)
    {
        char str[N];
        char ans[N];
        fscanf(f, "%s", str);
        fscanf(fans, "%s", ans);
        printf("#%d\n", i + 1);
        printf("������: ");
        wrscreen(str);
        abbr(str);
        printf("������ ����� ���������: ");
        wrscreen(str);
        printf("��������� ���������: ");
        wrscreen(ans);
        printf("���������: ");
        int j, error = 0;
        for (j = 0; j < strlen(str); ++j)
        {
            if(ans[j] != str[j])
            {
                printf("Fail.\n");
                error = 1;
                break;
            }
        }
        if (!error)
        {
            printf("Success.\n");
        }
        printf("\n=============================================================\n\n");
    }
    return 0;
}
