// Singly Circular Linked List
#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)

struct node 
{
    int data;
    struct node * next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : InsertFirst
// Description  : To insert Node at First
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = no;
    newn ->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn ->next = *first;
        *first = newn;
    }
    (*last) ->next = *first;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : InsertLast
// Description  : To insert Node at Last
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn =(PNODE)malloc(sizeof(NODE));

    newn ->data = no;
    newn ->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last) ->next = newn;
        *last = newn;
    }
    (*last) ->next = *first;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteFirst
// Description  : To Delete First Node
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first, PPNODE last)
{
    if(*first == NULL)
        return;

    if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        PNODE temp = *first;
        *first = (*first)->next;
        free(temp);
        (*last)->next = *first;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteLast
// Description  : To Delete Last Node
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first, PPNODE last)
{
    if(*first == NULL)
        return;

    if(*first == *last)
    {
        free(*last);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        PNODE temp = *first;

        while(temp->next != *last)
        {
            temp = temp->next;
        }

        free(*last);
        *last = temp;
        (*last)->next = *first;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : Display
// Description  : To Display the Linked List
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first, PNODE last)
{
    do
    {
        printf("| %d | ->",first ->data);
        first = first ->next;
    }while(first != last ->next);

    printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : Count
// Description  : To Count the Node from Linked List
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        first = first ->next;
    }while(first != last ->next);

    printf("\n");
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : InsertAtPos
// Description  : To insert Node at given Position
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;
    iSize = Count(*first, *last);

    if((pos < 1) || (pos > iSize +1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if(pos == iSize +1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn ->data = no;
        newn ->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp ->next;
        }

        newn ->next = temp ->next;
        temp ->next = newn;

        (*last) ->next = *first;
    }
}   

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : DeleteAtPos
// Description  : To Delete the Node At Given Position
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int iCnt = 0;
    int iSize = Count(*first, *last);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(pos == iSize)
    {
        DeleteLast(first, last);
    }
    else
    {
        PNODE temp = *first;
        PNODE target = NULL;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
            temp = temp->next;

        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : Main 
// Description  : Function calling from main is CallByAddress, CallValue.
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 19/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are : %d\n",iRet);

    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 111);
    InsertLast(&head, &tail, 121);
    
    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteFirst(&head, &tail);
    
    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteLast(&head, &tail);
    
    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are : %d\n",iRet);

    InsertAtPos(&head, &tail, 71, 3);
    
    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteAtPos(&head, &tail, 3);
    
    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of Nodes are : %d\n",iRet);

    return 0;
}
/*
    | 11 | ->| 21 | ->| 51 | ->
    Number of Nodes are : 3

    | 11 | ->| 21 | ->| 51 | ->| 121 | ->| 111 | ->| 101 | ->
    Number of Nodes are : 6

    | 21 | ->| 51 | ->| 121 | ->| 111 | ->| 101 | ->
    Number of Nodes are : 5

    | 21 | ->| 51 | ->| 121 | ->| 111 | ->
    Number of Nodes are : 4

    | 21 | ->| 51 | ->| 71 | ->| 121 | ->| 111 | ->
    Number of Nodes are : 5

    | 21 | ->| 51 | ->| 121 | ->| 111 | ->
    Number of Nodes are : 4
*/