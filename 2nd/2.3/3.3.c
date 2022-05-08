#include<stdio.h>
#include<stdlib.h>
long find_head(FILE*fp,int n)
{
    fseek(fp,SEEK_SET,0);
    int begin=0,i=0;
    char c;
    FILE*ptr=fp;
    if(n==1)
    {
        begin=5;
    }
    else
    {
        for(;i<n-2;)
        {
            c=fgetc(ptr);
            if(c=='\n')
            i++;
        }
        i=0;
        c=fgetc(ptr);
        for(;c!='\n';c=fgetc(ptr))
        {
            begin*=10;
            begin+=c-'0';
        }
        fseek(ptr,0,0);
    }
    for(;i<begin;)
    {
        c=fgetc(ptr);
        if(c=='\n')
        i++;
    }
    return ftell(ptr);
}
long find_end(FILE*fp,int n)
{
    fseek(fp,SEEK_SET,0);
    int end=0,i=0;
    char c;
    FILE*ptr=fp;
    for(;i<n-1;)
    {
        c=fgetc(ptr);
        if(c=='\n')
        i++;
    }
    i=0;
    c=fgetc(ptr);
    for(;c!='\n';c=fgetc(ptr))
    {
        end*=10;
        end+=c-'0';
    }
    fseek(ptr,SEEK_SET,0);
    for(;i<=end;)
    {
        c=fgetc(ptr);
        if(c=='\n')
        i++;
    }
    return ftell(ptr);
}
void clean(FILE*fp,int n)
{
    fseek(fp,SEEK_SET,0);
    FILE*ptr=fp;
    long begin=find_head(fp,n);
    long end=find_end(fp,n);
    char c=fgetc(ptr);
    for(;ftell(ptr)!=begin;fgetc(ptr));
    for(;ftell(ptr)!=end;c=fgetc(ptr))
    {
        if(c=='/'&&fgetc(ptr)=='*')
        {
            for(;(fgetc(ptr)=='*'&&fgetc(ptr)=='/')||ftell(ptr)==end;);
        }
        else
        {
            fseek(ptr,SEEK_CUR,-1);
            if(c=='/'&&fgetc(ptr)=='/')
            {
                for(;fgetc(ptr)!='\n';);
                puts("");
            }
            else
            {
                fseek(ptr,SEEK_CUR,-1);
                printf("%c",c);
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    FILE*fp=fopen("dict.dic","r");
    clean(fp,n);
    fclose(fp);
    system("pause");
    return 0;
}