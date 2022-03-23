#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
    int num;
    struct linklist*next;
}linklist;
linklist *creat()//创建
{
    int n=-1;
    linklist *head=NULL,*node=NULL,*end=NULL;
    head=(linklist*)malloc(sizeof(linklist));
    end=head;
    scanf("%d",&n);
    for(;n!=-1;)
    {
        node=(linklist*)malloc(sizeof(linklist));
        node->num=n;
        end->next=node;
        end=node;
        scanf("%d",&n);
    }
    end->next=NULL;
    return head;
}
int main()
{
    linklist*head=creat(),*node=NULL;
    int max,min,sum;
    node=head->next;
    max=node->num;
    min=node->num;
    sum=0;
    for(;node!=NULL;)
    {
        sum+=node->num;
        if(node->num>max)
        max=node->num;
        if(node->num<min)
        min=node->num;
        node=node->next;
    }
    printf("The maximum,minmum and the total are:%d %d %d\n",max,min,sum);
    linklist*temp;
    for(;head!=NULL;)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    system("pause");//提交时候把这个去掉就行（  OJ不需要
    return 0;
}