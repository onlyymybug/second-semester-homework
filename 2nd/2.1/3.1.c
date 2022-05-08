#include<stdio.h>
#include<stdlib.h>
void task1(FILE*fp)
{
    FILE*ptr=fp;
    int capital=0,lowercase=0,digit=0,others=0;
    char c=fgetc(ptr);
    for(;!feof(ptr);)
    {
        if(c>='A'&&c<='Z')
        capital++;
        else if(c>='a'&&c<='z')
        lowercase++;
        else if(c>='0'&&c<='9')
        digit++;
        else
        others++;
        c=fgetc(ptr);
    }
    printf("Task1:\n");
    printf("capital: %d\n",capital);
    printf("lowercase: %d\n",lowercase);
    printf("digit: %d\n",digit);
    printf("others: %d\n",others);
}
void task2(FILE*fp)
{
    FILE*ptr=fp;
    int max=0,min=0,line=0;
    char c=fgetc(ptr);
    for(int i=0;!feof(ptr);i++)
    {
        if(c=='\n')
        {
            line++;
            if(max<i)
            max=i;
            if(line==1)
            min=i;
            else if(min>i)
            min=i;
            i=-1;//因为还要++所以这是-1
        }
        c=fgetc(ptr);
    }
    printf("Task2:\n");
    printf("line: %d\n",line);
    printf("%d characters in max line.\n",max);
    printf("%d characters in min line.\n",min); 
}
void task3(FILE*fp)
{
    int capital[26]={0},lowercase[26]={0};
    char letter='A';
    FILE*ptr=fp;
    char c=fgetc(ptr);
    for(;!feof(ptr);)
    {
        if(c>='A'&&c<='Z')
        capital[c-'A']++;
        if(c>='a'&&c<='z')
        lowercase[c-'a']++;
        c=fgetc(ptr);
    }
    printf("Task3:\n");
    printf("CAPITAL:\n");
    for(int i=0;i<26;i++)
    {
        printf("%c:%d\n",'A'+i,capital[i]);
    }
    printf("LOWERCASE:\n");
    for(int i=0;i<26;i++)
    {
        printf("%c:%d\n",'a'+i,lowercase[i]);
    }
}
int main()
{
    FILE*fp=fopen("dict.dic","r");
    int n;
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        task1(fp);
        break;
    case 2:
        task2(fp);
        break;
    case 3:
        task3(fp);
        break;
    default:
        break;
    }
    fclose(fp);
    system("pause");
    return 0;
}