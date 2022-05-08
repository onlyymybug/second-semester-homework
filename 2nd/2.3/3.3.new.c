#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    FILE*fp=fopen("dict.dic","r");
    fgetc(fp);
    printf("%ld",ftell(fp));
    fgetc(fp);
    printf("%ld",ftell(fp));
    fgetc(fp);
    printf("%ld",ftell(fp));
    fgetc(fp);
    printf("%ld",ftell(fp));
    system("pause");
    return 0;
}