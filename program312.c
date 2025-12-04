#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
typedef struct node
{   
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Call by value 

void Display(PNODE first)
{

}
int Count(PNODE first)
{
    return 0;
}

// Call by adderess

void InsertFirst(PPNODE first, int no)
{}

void InsertLast(PPNODE first, int no)
{}

void InsertAtPose(PPNODE first, int no, int pos)
{}

int main()
{
    PNODE head = NULL;

    Display(head);
    Count(head);

    InsertFirst(&head, 11);
    InsertLast(&head, 21);
    InsertAtPose(&head, 51, 5);

    return 0;
}