#include<iostream>
using namespace std;

template <class T>
struct DoublyCLLnode
{
    T data; 
    DoublyCLLnode * next;
    DoublyCLLnode * prev;
};

template <class T>
class DoublyCLL
{
    private :
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public :
        DoublyCLL();
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
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Inside Constructer of DoublyCLL\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;

        first->prev = last;
        last->next = first;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Positiono.\n";
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

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next= target->next;
        target->next->prev = temp;

        delete target;
        iCount--;
    }
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *newn = NULL;
    int iCnt = 0;

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
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCLL<T>::Display()
{
    if(first == NULL)
    {
        return;
    }

    DoublyCLLnode<T> *temp = first;

    cout<<" <=> ";
    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    } while(temp != first);

    cout << "\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

int main()
{
    DoublyCLL<int> obj;

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