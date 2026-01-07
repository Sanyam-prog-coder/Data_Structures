#include<iostream>
using namespace std;

#pragma pack(1)
class stacknode
{
    public :
        int data;
        stacknode*next;

        stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class stack
{
    private :
        stacknode *first;
        int iCount;

    public :
        stack();
        void push(int);             // InsertFirst(int)
        int pop();                  // DeleteFirst()
        int peep();
        void Display();
        int Count();
};

stack :: stack()
{
    cout<<"Stack gets created Succefully...\n";
    this->first = NULL;
    this->iCount = 0;
}

void stack :: push(int no)
{
    stacknode *newn = NULL;

    newn = new stacknode(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

int stack :: pop()
{
    int Value = 0;
    stacknode *temp = this->first;

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

int stack :: peep()
{
    int Value = 0;

    if(this->first == NULL)
    {
        cout<<"stack is Empty\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

void stack :: Display()
{
    stacknode *temp = this->first;

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

int stack :: Count()
{
    return this->iCount;
}

int main()
{
    stack *sobj = new stack();

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