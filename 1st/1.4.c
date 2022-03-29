//链表交换 交换链表中[s1,t1]和[s2,t2]两段
//s1<=t1<s2<=t2
/*
input:
1 2 3 4 5 6 7 8 9 10 -1
1 1 4 7
output:
The new list is:4 5 6 7 2 3 1 8 9 10
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
void exchange_linklist(linklist*head,int s1,int t1,int s2,int t2)
{
	linklist*node=head;
	linklist*ss1=NULL,*tt1=NULL,*ss2=NULL,*tt2=NULL;
	int i=1;
	for(;i<=t2+1;i++,node=node->next)
	{
		if(i==s1)
		{
			ss1=node;
		}
		if(i==t1+1)
		{
			tt1=node;
		}
		if(i==s2)
		{
			ss2=node;
		}
		if(i==t2+1)
		{
			tt2=node;
		}
	}
	linklist*temps=ss1->next,*tempt=tt2->next;
	if(s2-t1!=1)//如果交换的两段连着的话if下面的就不行了
	{
	    ss1->next=ss2->next;
	    tt2->next=tt1->next;
	    ss2->next=temps;
	    tt1->next=tempt;
	}
	else
	{
		ss1->next=ss2->next;
		tt2->next=temps;
		tt1->next=tempt;
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
    int s1,t1,s2,t2;
    scanf("%d %d %d %d",&s1,&t1,&s2,&t2);
	exchange_linklist(head,s1,t1,s2,t2);
	printf("The new list is:");
	print_linklist(head);
	free_linklist(head);
	system("pause");
	return 0;
}