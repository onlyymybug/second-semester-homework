//链表归并 A B两个递增正整数链表 分别无重复元素
//将B归并到A，使得A仍然递增，A中已有的留在B中
/*
input1:
1 3 4 5 6 7 -1
2 3 6 8 9 10 11 -1
output1:
The new list A:1 2 3 4 5 6 7 8 9 10 11
The new list B:3 6
input2:
-1
-1
output2:
There is no item in A list.
There is no item in B list.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int num;
	struct linklist*next;
}linklist;
linklist *creat_linklist()//creat a linklist
{
	int n=-1, count=0;
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
		count++;
	}
	end->next=NULL;
	head->num=count-2;
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
void print_linklist(linklist*head,char letter)
{
    linklist*node=head->next;
    if(node!=NULL)
    {
        printf("The new list %c:",letter);
        for(;node->next!=NULL;)
        {
            printf("%d ",node->num);
            node=node->next;
        }
        printf("%d\n",node->num);
    }
    else
    printf("There is no item in %c list.\n",letter);
}
void merge_linklist(linklist*headA,linklist*headB)
{
    linklist*nodeA=headA,*nodeB=headB,*temp1=NULL,*temp2=NULL;
    for(;nodeA->next!=NULL&&nodeB->next!=NULL;)
    {
        if(nodeA->next->num>nodeB->next->num)
        {
            temp1=nodeB->next;
            temp2=nodeA->next;
            nodeB->next=temp1->next;
            nodeA->next=temp1;
            nodeA->next->next=temp2;
        }
        else if(nodeA->next->num==nodeB->next->num)
        {
            nodeB=nodeB->next;
        }
        nodeA=nodeA->next;
    }
    if(nodeB->next!=NULL)
    {
        nodeA->next=nodeB->next;
        nodeB->next=NULL;
    }
}
int main()
{
    linklist*headA=creat_linklist();
    linklist*headB=creat_linklist();
    merge_linklist(headA,headB);
    print_linklist(headA,'A');
    print_linklist(headB,'B');
    free_linklist(headA);
    free_linklist(headB);
    system("pause");
    return 0;
}