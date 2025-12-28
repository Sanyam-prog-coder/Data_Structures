// Singly Circular

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
};

typedef struct node NODE;
typedef struct node* PNODE;

///////////////////////////////////////////////////////////////////////////////
//
// Class    : SinglyCL
// Description  : All 8 FucntionCall with Logic
// Auther   : Sanyam BhupendraKumar Ravne
// Date : 28/12/2025
//
///////////////////////////////////////////////////////////////////////////////

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount; 

    public:
        SinglyCL()
        {
            cout<<"Object of SinglyCL gets created.\n";
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

            if(this->first == NULL)
            {
                this->first = newn;
                this->last = newn;

                newn->next = newn;
            }
            else
            {
                newn->next = this->first;
                this->first = newn;
                this->last->next = newn;
            }
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

            if(this->first == NULL)
            {
                this->first = newn;
                this->last = newn;

                newn->next = newn;
            }
            else
            {
                this->last->next = newn;
                this->last = newn;
                this->last->next = this->first;            
            }
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
            if(pos < 1 || pos > iCount + 1)
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
                PNODE newn = new NODE;
                newn->data = no;
                newn->next = NULL;

                PNODE temp = first;

                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;             
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
                PNODE temp = first;

                first = first->next;
                delete temp;

                last->next = first;
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
                PNODE temp = first;
                while(temp->next != last)
                {
                    temp = temp->next;
                }

                delete last;
                last = temp;
                last->next = first;
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
            if(pos < 1 || pos > iCount)
            {
                cout<<"INvalid Position\n";
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
                PNODE temp = this->first;
                int iCnt = 0;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp->next;
                }

                PNODE target = temp->next;
                temp->next = target->next;
                delete target;

                this->iCount--;
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
            if(this->first == NULL)
            {
                cout<<"Linked list is empty\n";
                return;
            }

            PNODE temp = this->first;
            cout<<"->";

            do
            {
                cout<<"| "<<temp->data<<" |-> ";
                temp = temp->next;
            } while(temp != first);

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
    SinglyCL obj;
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

Object of SinglyCL gets created.
->| 11 |-> | 21 |-> | 51 |->
Number of nodes are : 3
->| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |->
Number of nodes are : 6
->| 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |->
Number of nodes are : 5
->| 21 |-> | 51 |-> | 101 |-> | 111 |->
Number of nodes are : 4
->| 21 |-> | 51 |-> | 101 |-> | 105 |-> | 111 |->
Number of nodes are : 5
->| 21 |-> | 51 |-> | 101 |-> | 111 |->
Number of nodes are : 4

*/