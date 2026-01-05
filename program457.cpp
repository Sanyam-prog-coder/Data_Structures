#include<iostream>
using namespace std;

template <class T>
struct SinglyLLLnode
{
    T data;
    SinglyLLLnode *next;
};

template <class T>
class SinglyLLL
{
private:
    SinglyLLLnode<T> *first; 
    int iCount;

public:
    SinglyLLL();
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
SinglyLLL<T>::SinglyLLL()
{
    cout << "Inside Constructor of SinglyLLL\n";
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = new SinglyLLLnode<T>;
    newn->data = no;
    newn->next = first;
    first = newn;
    iCount++;
}

template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> *newn = new SinglyLLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        SinglyLLLnode<T> *temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    if(first == NULL)
        return;

    SinglyLLLnode<T> *temp = first;
    first = first->next;
    delete temp;
    iCount--;
}

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    if(first == NULL)
        return;

    if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        SinglyLLLnode<T> *temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> *temp = first;
    while(temp != NULL)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int SinglyLLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid Position\n";
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
        SinglyLLLnode<T> *newn = new SinglyLLLnode<T>;
        newn->data = no;

        SinglyLLLnode<T> *temp = first;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout << "Invalid Position\n";
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
        SinglyLLLnode<T> *temp = first;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        SinglyLLLnode<T> *target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

int main()
{
    SinglyLLL<int> obj;

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