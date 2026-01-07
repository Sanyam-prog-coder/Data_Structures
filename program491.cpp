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

}

void stack :: push(int no)
{

}

int stack :: pop()
{
    return 0;
}

int stack :: peep()
{
    return 0;
}

void stack :: Display()
{
    
}

int stack :: Count()
{
    return this->iCount;
}

int main()
{
    stack *sobj = new stack();

    delete sobj;

    return 0;
}