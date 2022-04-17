#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define SIZE 5        
int s[SIZE],top=-1;      
 
int Sfull()
{                    
    if(top == SIZE-1) return 1;
    return 0;
}
 
int Sempty()
{                   
    if(top == -1) return 1;
    return 0;
}

void push(int elem)
{                       
    if( Sfull()) printf("\n\n Overflow!!!!\n\n");
    else
    {
        ++top;
        s[top]=elem;
    }
}
 
int pop()
{                    
    int elem;
    if(Sempty()){ printf("\n\nUnderflow!!!!\n\n");
    return(-1); }
    else
    {
        elem=s[top];
        top--;
        return(elem);
    }
}
 
void display()
{                 
    int i;
    if(Sempty()) printf(" \n Empty Stack\n");
    else
    {
        for(i=0;i<=top;i++)
            printf("%d\n",s[i]);
        printf("^Top");
    }
}
 
void main()
{                         
    int opn,elem;
    do
    {
        printf("\n ### Stack Operations ### \n\n");
        printf("\n Press 1-Push, 2-Pop,3-Display,4-Exit\n");
        printf("\n Your option ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1: printf("\n\nRead the element to be pushed ?");
            scanf("%d",&elem);
            push(elem); break;
        case 2: elem=pop();
            if( elem != -1)
                printf("\n\nPopped Element is %d \n",elem);
            break;
        case 3: printf("\n\nStatus of Stack\n\n");
            display(); break;
        case 4: printf("\n\n Terminating \n\n"); break;
        default: printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
        printf("\n\n\n\n  Press a Key to Continue . . . ");
        getch();
    }while(opn != 4);
}
