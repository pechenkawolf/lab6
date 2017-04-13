#include <windows.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void incert(char *a, char *b, size_t j)
{
    int i=0;
    char k;
    while(*(b+i) != '\0')
    {
        k=*(a+j);
        *(a+j)=*(b+i);
        *(b+i)=k;
        ++i;
        ++j;
    }
    i=0;
    while(*(b+i) != '\0')
    {
        *(a+j)=*(b+i);
        ++j;
        ++i;
    }
    *(a+j)='\0';
}

void program(FILE *f1, FILE *f2)
{
    int k;
    int i=0,j;
    char a[100][100];
    char b[5];
    while(!feof(f1))
    {
        fscanf (f1,"%s", a[i]);
        k=strlen(a[i]);
        if( k > 10)
        {
            itoa(k-2, b, 10);
            incert(a[i], b, 1);
            j=strlen(b);
            a[i][j+1]=a[i][k-1];
            a[i][j+2]='\0';
        }
        ++i;
    }

    for(j=0;j<i;++j)
    {
        fprintf (f2, "%s \n", a[j]);

    }
    //printf("%s\n%s\n%s\n", a[0],a[1],a[2]);
}
void test()
{
    FILE *f1,*f2;
    f1=fopen("test-input.txt","r");
    f2=fopen("test-output.txt","w");
    program(f1,f2);
    fclose(f1);
    fclose(f2);
    f2=fopen("test-output.txt","r");
    char a[5][10];
    int i;

    for(i=0;i<5;++i)
        fscanf(f2,"%s",a[i]);

    printf("TESTS:\n");
    if(strcmp(a[0],"case")) printf("1.Fall\n");
    else printf("1.Ok\n");

    if(strcmp(a[1],"l10n")) printf("1.Fall\n");
    else printf("1.Ok\n");

    if(strcmp(a[2],"i15n")) printf("1.Fall\n");
    else printf("1.Ok\n");

    if(strcmp(a[3],"end")) printf("1.Fall\n");
    else printf("1.Ok\n");

    if(strcmp(a[4],"milk")) printf("1.Fall\n");
    else printf("1.Ok\n");
    fclose(f2);
}
