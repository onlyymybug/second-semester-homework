//链表排序
//单链表 -1 为结束标志 输入正整数序列 输出排序后的序列
//input:49 38 65 97 76 13 27 49 -1
//output:The new list is:13 27 38 49 49 65 76 97
//奶奶滴 我滴指针 互换辣
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
void exchange_linklist(linklist*node)
{
    linklist*front=node,*behind=node->next;
    front->next=behind->next;//先删掉两数中前面的数
    behind->next=front->next->next;
    front->next->next=behind;//然后插到第二个数后面
}//欸应该拆成俩函数方便后面用
void sort_linklist(linklist*head)
{
    int n=lenth_linklist(head);
    for(int i=1;i<=n-1;i++)
    {
        linklist*node=head;
        for(int j=1;j<=n-i;j++)
        {
            if(node->next->num>=node->next->next->num)
            {//因为不能直接改exchange函数参数里指针指向的那个
                exchange_linklist(node);
            }//所有就比较且换next->num和next->next->num
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
    linklist*head=creat_linklist();
    sort_linklist(head);
    printf("The new list is:");
    print_linklist(head);
    free_linklist(head);
    system("pause");
    return 0;
}