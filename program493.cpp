#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
class stacknode
{
    public :
        T data;
        stacknode<T>*next;

        stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class stack
{
    private :
        stacknode<T> *first;
        int iCount;

    public :
        stack();
        void push(T);             
        T pop();                
        T peep();
        void Display();
        int Count();
};

template<class T>
stack<T> :: stack()
{
    cout<<"Stack gets created Succefully...\n";

    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void stack<T> :: push(T no)
{
    stacknode<T> *newn = NULL;

    newn = new stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template<class T>
T stack<T> :: pop()
{
    T Value = 0;
    stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template<class T>
T stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"stack is Empty\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

template<class T>
void stack<T> :: Display()
{
    stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template<class T>
int stack<T> :: Count()
{
    return this->iCount;
}

int main()
{
    stack<int> *sobj = new stack<int>();

    sobj->push(11);
    sobj->push(21);
    sobj->push(51);
    sobj->push(101);

    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";

    cout<<"Return Value of Peep is : "<<sobj->peep()<<"\n";
    
    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";

    cout<<"Poped Element is : "<<sobj->pop()<<"\n";

    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";

    cout<<"Poped Element is : "<<sobj->pop()<<"\n";

    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";

    sobj->push(121);

    sobj->Display();
    cout<<"Number of Elements int Stack Are : "<<sobj->Count()<<"\n";
    
    delete sobj;

    return 0;
}