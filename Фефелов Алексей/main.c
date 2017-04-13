#include <windows.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include"functions.h"

int main()
{
    FILE *f1,*f2;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    program(f1,f2);
    test();
    fclose(f1);
    fclose(f2);
    return 0;
}
