#include<conio.h>
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

NODE *concat(NODE *list1, NODE *list2);

NODE *concat(NODE *list1, NODE *list2){
	NODE *p;
	if (list1==NULL) return list2;
	else if (list2==NULL) return list1;
	p=list1;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=list2;
	return list1;
}

int isEmpty(){
	if (first==NULL) return 1;
	else return 0;
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

main()
{
	int ch;
	int element;
    printf("\nSingle Linked List");
    printf("\n------------");
    printf("\n1.Insert at first list\n2.Insert at second list\n3.Concatenate first+second\n4.Exit");
    printf("\n\n-->Enter Your Choice:");
    do{
    scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\n-->Enter value for first list:");scanf("%d",&element);insert(element, 1); display(first[1]);break;
            case 2: printf("\n-->Enter value for second list:");scanf("%d",&element);insert(element, 2);display(first[2]);break;
            case 3:concat(first[1],first[2]);display(first[1]);break;
			case 4:exit(0);
            default:printf("\nError-->Enter a valid choice!!"); exit(0);

    }}

    while(1);



}
