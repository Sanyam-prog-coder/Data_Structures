// Doubly LLL

#include<iostream>
using namespace std;

template <class T>
struct DoublyLLLnode
{
    T data;
    DoublyLLLnode * next;
    DoublyLLLnode * prev;
};

template<class T>
class DoublyLLL
{
    private :
        DoublyLLLnode<T> *first;
        DoublyLLLnode<T> *last;
        int iCount;

    public :
        DoublyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
};

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"Inside Constructer of DoublyLLL\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = new DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

template<class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> * newn = new DoublyLLLnode<T>;
    DoublyLLLnode<T> * temp = first;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template<class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        DoublyLLLnode<T> *temp = first;

        first = first->next;
        first->prev = NULL;
        delete temp;
    }
    iCount--;
}

template<class T>
void DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first ->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> *temp = first;

    cout<<"\nNULL <==>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <==>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;
    
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid Position";
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
        newn = new DoublyLLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        newn->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position";
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
        temp = first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
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

int main()
{
    DoublyLLL<int> obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout << "Number of nodes are: " << obj.Count() << "\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    cout << "Number of nodes are: " << obj.Count() << "\n";

    obj.DeleteFirst();
    obj.Display();
    cout << "Number of nodes are: " << obj.Count() << "\n";

    obj.DeleteLast();
    obj.Display();
    cout << "Number of nodes are: " << obj.Count() << "\n";

    obj.InsertAtPos(105, 4);
    obj.Display();
    cout << "Number of nodes are: " << obj.Count() << "\n";

    obj.DeleteAtPos(4);
    obj.Display();
    cout << "Number of nodes are: " << obj.Count() << "\n";

    return 0;
}