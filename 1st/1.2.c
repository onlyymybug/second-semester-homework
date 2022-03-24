#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
    int num;
    struct linklist*next;
}linklist;
linklist *creat_linklist()//creat a linklist
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
void free_linklist(linklist*head)//free a linklist
{
    linklist*temp;
    for(;head!=NULL;)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
int lenth_linklist(linklist*head)//return the length of a linklist
{
    int n=-1;//not include head,is the truth lenth
    for(;head!=NULL;)
    {
        n++;
        head=head->next;
    }
    return n;
}
void exchange_linklist(linklist*node1)
//node1:ptr to first link
{
    int temp=node1->num;
    node1->num=node1->next->num;
    node1->next->num=temp;
}//题目要求换指针域 先写了个换数据的测试了下sort
void sort_linklist(linklist*head)
{
    int n=lenth_linklist(head);
    for(int i=1;i<=n-1;i++)
    {
        linklist*node=head->next;
        for(int j=1;j<=n-i;j++)
        {
            if(node->num>=node->next->num)
            {
                exchange_linklist(node);
            }
            node=node->next;
        }
    }
}
void print_linklist(linklist*head)
{
    linklist*node=head->next;
    for(;node->next!=NULL;)
    {
        printf("%d ",node->num);
        node=node->next;
    }
    printf("%d\n",node->num);
}
int main()
{
    linklist*head=creat_linklist(),*node=NULL;
    sort_linklist(head);
    printf("The new list is:");
    print_linklist(head);
    free_linklist(head);
    system("pause");
    return 0;
}