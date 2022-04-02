//拆分链表 题太长了
//L中乱序元素 字母扔A 数字扔B 其他扔C 并排序
/*
input:a c 3 b a d 6 , & j m 8 7 2 V -1
output:
The list A is: V a a b c d j m
The list B is: 2 3 6 7 8
The list C is: & ,
input:z m v 1 a K 2 m p 9 a 0 a d -1
output:
The list A is: K a a a d m m p v z
The list B is: 0 1 2 9
There is no item in C list.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linklist
{
	char letter[3];
	struct linklist*next;
}linklist;
linklist *creat_linklist()//no problem
{
	char s[]="-1", count=0;
	linklist *head=NULL,*node=NULL,*end=NULL;
	head=(linklist*)malloc(sizeof(linklist));
	end=head;
	scanf("%s",s);
	for(;strcmp(s,"-1")!=0;)
	{
		node=(linklist*)malloc(sizeof(linklist));
		strcpy(node->letter,s);
		end->next=node;
		end=node;
		scanf("%s",s);
		count++;
	}
	end->next=NULL;;
	return head;
}
linklist *creat_empty_linklist()
{
	linklist*head=(linklist*)malloc(sizeof(linklist));
	head->next=NULL;
	return head;
}
void move_linklist(linklist*node1,linklist*node2)
{//将node1->next的链结插到node2->next
    linklist*temp1=node1->next,*temp2=node2->next;
    node1->next=node1->next->next;
    node2->next=temp1;
    node2->next->next=temp2;
}
void classify_linklist(linklist*headL,linklist*headA,linklist*headB,linklist*headC)
{//分类
    linklist*nodeL=headL,*nodeA=headA,*nodeB=headB,*nodeC=headC;
    for(;nodeL->next!=NULL;)
    {
        if((strcmp(nodeL->next->letter,"z")<=0&&strcmp(nodeL->next->letter,"a")>=0)||(strcmp(nodeL->next->letter,"A")>=0&&strcmp(nodeL->next->letter,"Z")<=0))
        {
            move_linklist(nodeL,nodeA);
            nodeA=nodeA->next;
        }
        else if(strcmp(nodeL->next->letter,"0")>=0&&strcmp(nodeL->next->letter,"9")<=0)
        {
            move_linklist(nodeL,nodeB);
            nodeB=nodeB->next;
        }
        else
        {
            move_linklist(nodeL,nodeC);
            nodeC=nodeC->next;
        }
    }
}
void exchange_linklist(linklist*node)
{
    linklist*front=node,*behind=node->next;
    front->next=behind->next;
    behind->next=front->next->next;
    front->next->next=behind;
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
void sort_linklist(linklist*head)
{
    int n=lenth_linklist(head);
    for(int i=1;i<=n-1;i++)
    {
        linklist*node=head;
        for(int j=1;j<=n-i;j++)
        {
            if(strcmp(node->next->letter,node->next->next->letter)>0)
            {
                exchange_linklist(node);
            }
            node=node->next;
        }
    }
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
void print_linklist(linklist*head,char c)
{
    linklist*node=head->next;
    if(node==NULL)
    {
        printf("There is no item in %c list.\n",c);
    }
    else
    {
        printf("The list %c is: ",c);
        for(;node->next!=NULL;)
        {
            printf("%s ",node->letter);
            node=node->next;
        }
        printf("%s\n",node->letter);
    }
}
int main()
{
	linklist*headL=creat_linklist();
	linklist*headA=creat_empty_linklist();
	linklist*headB=creat_empty_linklist();
	linklist*headC=creat_empty_linklist();
    classify_linklist(headL,headA,headB,headC);
    sort_linklist(headA);
    sort_linklist(headB);
    sort_linklist(headC);
    print_linklist(headA,'A');
    print_linklist(headB,'B');
    print_linklist(headC,'C');
	free_linklist(headA);
	free_linklist(headB);
	free_linklist(headC);
	free_linklist(headL);
	system("pause");
	return 0;
}