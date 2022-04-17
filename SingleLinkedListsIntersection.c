#include<stdio.h>
#include<stdlib.h>

void insert();
void display();

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *temp=NULL;
NODE *first[3]={NULL,NULL,NULL};
NODE *last[3]={NULL,NULL,NULL};



NODE *search(NODE *list,int val)
{
NODE *ptr;
for(ptr=list;ptr!=NULL && ptr->data!=val;ptr=ptr->next);
return(ptr);
}

int isPresent (NODE *head, int data)
{
struct node *t = head;
while (t != NULL)
{
if (t->data == data)
return 1;
t = t->next;
}
return 0;
}


NODE *getIntersection (NODE *head1, NODE *head2)
{

NODE *t1 = head1;

while (t1 != NULL)
{
if (isPresent(head2, t1->data))
insert(t1->data, 0);
t1 = t1->next;
}

return first[0];
}

void insert(int elem, int listNo)
{
	temp=(struct node*)malloc(sizeof(struct node));
    temp->data=elem;
    temp->next=NULL;
    if(first[listNo]==NULL)
    {
        first[listNo]=temp;
        last[listNo]=temp;
    }
    else
    {
        last[listNo]->next=temp;
        last[listNo]=temp;
    }
	
}

void display(NODE *first)
{
    temp=first;
    printf("First->");
    while(temp!=NULL)
    {
   
    printf("|%d| --> ",temp->data);
    temp=temp->next;
    }
      printf("NULL");
}

void main()
{

	NODE *pom;
    printf("Single linked list list1 \n");
    insert(5,1);
    insert(20,1);
    insert(100,1);
    display(first[1]);
    insert(100,2);
    insert(5,2);
    insert(300,2);
    printf("\n Single linked list list2 \n");
    display(first[2]);
    pom=getIntersection(first[1],first[2]);
    printf("\n The intersection list is: ");
    display(pom);
} 