#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;
        
    ArrayX(int iNo);
    ~ArrayX();
    void Accept();
    void Display();
    bool LinearSearch(int iNo);
    bool BiDirectionalSearch(int iNo);
    bool ChechSorted();
    bool BinarySearch(int iNo);
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside constructor\n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside destructor\n";
    delete [] Arr;
}

void ArrayX :: Accept()
{
    int iCnt = 0;

    cout<<"Enter the elements : \n";

    cin>>Arr[iCnt];

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt -1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }

   // Sorted = ChechSorted();
}

void ArrayX :: Display()
{
    int iCnt = 0;

    cout<<"Elements of the array are : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

bool ArrayX :: LinearSearch(int iNo)
{
    bool bFlag = false;
    int i = 0;
    
    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == iNo)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

bool ArrayX :: BiDirectionalSearch(int iNo)
{
    bool bFlag = false;
    int iStart = 0;
    int iEnd = 0;
    
    for(iStart = 0, iEnd = iSize -1; iStart <= iEnd; iStart++, iEnd--)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

//  0   1   2   3   4   5   6   7   8   9
// 12   14  17  24  28  36  48  52  52  65

bool ArrayX :: ChechSorted()
{
    int i = 0;
    bool bFalg = true;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i + 1])
        {
            bFalg = false;
            break;
        }
    }
    return bFalg;
}

bool ArrayX :: BinarySearch(int iNo)
{
    int iStart = 0, iMid = 0, iEnd = 0;
    bool bFalg = false;

    iStart = 0;
    iEnd = iSize -1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == iNo)
        {
            bFalg = true;
            break;
        }
        else if(iNo < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if(iNo > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }

    return bFalg;
}

int main()
{   
    int iValue = 0;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);

    aobj.Accept();

    aobj.Display();

    /*if(aobj.LinearSearch(21))
    {
        cout<<"Element is Present\n";
    }
    else
    {    
        cout<<"There is No such Element\n";
    }

    if(aobj.BiDirectionalSearch(21))
    {
        cout<<"Element is Present\n";
    }
    else
    {    
        cout<<"There is No such Element\n";
    }

    if(aobj.Sorted == true)
    {
        cout<<"Data is Sorted\n";
    }
    else
    {
        cout<<"Data is not Sorted\n";
    }*/

    if(aobj.BinarySearch(25))
    {
        cout<<"Element is Present\n";
    }
    else
    {
        cout<<"There is no such element\n";
    }

    return 0;
}