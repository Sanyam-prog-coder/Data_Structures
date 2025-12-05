#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Functions    : InsertFirst   InsertLast
// Description  : Singly linear linked list data structure
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InserFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)      // Limked List is Empty
    {
        (*first) = newn;
    }
    else                    // Linked List  contains atleast 1 node
    {
        newn -> next = (*first);
        (*first) = newn;
    }
}

void InserLast(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)      // Limked List is Empty
    {
        *first = newn;
    }
    else                    // Linked List  contains atleast 1 node
    {

    }
}

int main()
{
    PNODE head = NULL;

    InserFirst(&head, 51);
    InserFirst(&head, 21);
    InserFirst(&head, 11);

    return 0;
}