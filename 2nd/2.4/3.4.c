#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 int main()
{
    int count=0,i=0,j=0,m=0,n=0,start=0,flag = 1;
    FILE*fp;
    char**word=(char**)malloc(sizeof(char*)*10);
    char ch,passage[1200],*s;
    for(;(ch = getchar())!=EOF;)
    {
        passage[i]=ch;
        i++;
    }
    passage[i]='\0';
    if((fp = fopen("dict.dic", "r")) == NULL)
    printf("open file error!");
    else
    {
        while (!feof(fp))
        {
            word[count]=(char*)malloc(sizeof(char)*11);
            fgets(word[count],20,fp);
            word[count][strlen(word[count])-1]='\0';
            if (feof(fp))
            break;
            count++;
        }
        fclose(fp);
    }
    i=0;
    for(;i<count;)
    {
        j=0;
        s=word[i];
        while(passage[j]!='\0')
        {
            if(passage[j]==s[0])
            {
                start=j;
                for(m=1;s[m]!='\0';m++)
                {
                    if(s[m]!=passage[++j])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    passage[start]='@';
                    for (n=start+1;n<=j;n++)
                    passage[n]='#';
                    j=j+1;
                }
                else
                {
                    j=start+1;
                    flag=1;
                }
            }
            else
            j++;
        }
        i++;
    }
    for(i=0;passage[i]!='\0';i++)
    {
        if (passage[i]=='@')
        printf("!@#$%^&*");
        else if(passage[i]!='#')
        printf("%c",passage[i]);
    }
    system("pause");
    return 0;
}