#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Functions    : InsertFirst   InsertLast  Display Count DeleteFirst   DeleteLast
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
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)      // Limked List is Empty
    {
        *first = newn;
    }
    else                    // Linked List  contains atleast 1 node
    {
        temp = *first;

        while(temp -> next != NULL )
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first -> data);
        first = first -> next;
    }
    printf("NULL \n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)                 // Case I
    {
        return;
    }
    else if((*first) -> next == NULL)   // Case II
    {
        free(*first);
        *first = NULL;
    }
    else                                // Case III
    {
        temp = *first;
        *first = (*first) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)                // Case I
    {
        return;
    }
    else if((*first) -> next == NULL)   // Case II
    {
        free(*first);
        *first = NULL;
    }
    else                                // Case III
    {
        temp = *first;
        
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InserFirst(&head, 75);
    InserFirst(&head, 51);
    InserFirst(&head, 21);
    InserFirst(&head, 11);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InserLast(&head, 101);
    InserLast(&head, 111);
    InserLast(&head, 121);
    
    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);
    
    return 0;
}
/*
| 11 |->| 21 |->| 51 |->| 75 |->NULL
Number of nodes are : 4
| 11 |->| 21 |->| 51 |->| 75 |->| 101 |->| 111 |->| 121 |->NULL
Number of nodes are : 7
| 21 |->| 51 |->| 75 |->| 101 |->| 111 |->| 121 |->NULL
Number of nodes are : 6
| 21 |->| 51 |->| 75 |->| 101 |->| 111 |->NULL
Number of nodes are : 5
*/