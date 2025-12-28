// Doubly Circular

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Function : structure
// Description  : To create a node of 20 byte which points to prev ans next
// Auther   : Sanyam BhupendraKumar Ravne
// Date : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

///////////////////////////////////////////////////////////////////////////////
//
// Class    : DoublyCL
// Description  : All 8 FucntionCall with Logic
// Auther   : Sanyam BhupendraKumar Ravne
// Date : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCL()
        {
            cout<<"Object of DoublyCL gets created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }
///////////////////////////////////////////////////////////////////////////////
//
// Function : InsertFirst
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn ->data = no;
            newn ->next = NULL;
            newn ->prev = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                newn->next = this->first;
                this->first->prev = newn;
                this->first = newn;
            }
            this->last->next = this->first;
            this->first->prev = this->last;
            this->iCount++;
        }
///////////////////////////////////////////////////////////////////////////////
//
// Function : InsertLast
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
        void InsertLast(int no)
        {
            PNODE newn = NULL;
            
            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL && this->last == NULL)
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                this->last->next = newn;
                newn->prev = this->last;
                this->last = newn;
            }
            this->last->next = this->first;
            this->first->prev = this->last;
            this->iCount++;
        }
///////////////////////////////////////////////////////////////////////////////
//
// Function : InsertAtPos
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            int iCnt = 0;

            if(pos < 1 || pos > this->iCount + 1)
            {
                cout<<"Invalid Position.\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = this->first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                newn->next->prev =newn;

                temp->next = newn;
                newn->prev = temp;
                
                this->iCount++;
            }
        }
///////////////////////////////////////////////////////////////////////////////
//
// Function : DeleteFirst
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
        void DeleteFirst()
        {
            if(this->first == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                this->first = this->first->next;
                delete this->first->prev;

                this->first->prev = this->last;
                this->last->next = this->first;
            }
            this->iCount--;
        }
///////////////////////////////////////////////////////////////////////////////
//
// Function : DeleteLast
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
        void DeleteLast()
        {
            if(this->first == NULL && this->last == NULL)
            {
                return;
            }
            else if(this->first == this->last)
            {
                delete this->first;
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                this->last = this->last->prev;
                delete this->last->next;

                this->last->next = this->first;
                this->first->prev = this->last;
            }
            this->iCount--;
        }
///////////////////////////////////////////////////////////////////////////////
//
// Function : DeleteAtPos
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int iCnt = 0;

            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid Position.\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = this->first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp->next;
                }

                target = temp->next;

                temp->next = target->next;
                target->next->prev = temp;

                delete target;
                iCount--;
            }
        }
///////////////////////////////////////////////////////////////////////////////
//
// Function : Display
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
        void Display()
        {
            if(first == NULL)
            {
                cout<<"Linked List is Empty.\n";
                return;
            }

            PNODE temp = first;

            cout<<" <=> ";
            do
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            }while(temp != first);

            cout<<"\n";
        }
///////////////////////////////////////////////////////////////////////////////
//
// Function : Count
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
        int Count()
        {
            return iCount;
        }
};
///////////////////////////////////////////////////////////////////////////////
//
// Function : Main
// Description : To Call the Functions callByValue And CallByAddress
// Auther   : Sanyam BhupendraKumar Ravne
// Date     : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////
int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    return 0;
}
/*

Object of DoublyCL gets created.
 <=> | 11 | <=> | 21 | <=> | 51 | <=>
Number of nodes are : 3
 <=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of nodes are : 6
 <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of nodes are : 5
 <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>
Number of nodes are : 4
 <=> | 21 | <=> | 51 | <=> | 101 | <=> | 105 | <=> | 111 | <=>
Number of nodes are : 5
 <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>
Number of nodes are : 4

*/