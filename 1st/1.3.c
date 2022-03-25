//判断B链表是否为A链表的连续子序列
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
int compare_linklist(linklist*head1,linklist*head2)
{
	linklist*node1=head1->next;
	if(lenth_linklist(head1)<lenth_linklist(head2))
	{
		return 0;
	}
	else
	{
		for(linklist*temp;node1!=NULL;node1=temp->next)
		{
            temp=node1;
			if(node1->num==head2->next->num)
			{
				linklist*node2=head2->next;
				for(;node2!=NULL&&node1->num==node2->num;node2=node2->next)
                {
                    if(node1->num!=node2->num)
                    {
                        node2=head2->next;
                        break;
                    }
                    if(node1->next==NULL&&node2->next!=NULL)
                    {
                        return 0;
                    }
                    if(node2->next==NULL)
                    {
                        return 1;
                    }
                    node1=node1->next;
                }
			}
		}
		return 0;
	}
}
int main() 
{
	linklist*head1=creat_linklist();
	linklist*head2=creat_linklist();
	int n=compare_linklist(head1,head2);
	if(n==1)
	{
		printf("ListB is the sub sequence of ListA.\n");
	}
	else
	{
		printf("ListB is not the sub sequence of ListA.\n");
	}
	free_linklist(head1);
	free_linklist(head2);
	system("pause");
	return 0;
}