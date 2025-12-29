// Doubly Circular

/////////////////////////////////////////////////////////////////////////////////////
///
/// Class    : node
/// Description  : Structure Class
/// Auther   : Sanyam BhupendraKumar Ravne
/// Date     : 29/12/2025
///
/////////////////////////////////////////////////////////////////////////////////////

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Class       : DoublyCL
/// Description : Constructer and Destructer
/// Auther  : Sanyam BhupendraKmar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////

class DoublyCL
{
    private node first;
    private node last;
    
    private int iCount;

    public DoublyCL()
    {
        System.out.println("Object of DoublyCL gets created.");
        
        this.first = null;
        this.last = null;
        
        this.iCount = 0;
    }
/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : InsertFirst
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
///////////////////////////////////////////////////////////////////////////////////// 
    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first.prev = newn;
            this.first = newn;
        }
        this.last.next = this.first;
        this.first.prev = this.last;
        this.iCount++;
    }
/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : InsertLast
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////
    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node(no);

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            newn.prev = this.last;
            this.last = newn;
        }
        this.last.next = this.first;
        this.first.prev = this.last;
        this.iCount++;
    }
/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : InsertAtPos
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////
    public void InsertAtPos(int no, int pos)
    {
        node temp = null;
        node newn = null;
        int iCnt = 0;

        if(pos < 1 || pos > this.iCount + 1)
        {
            System.out.println("Invalid Position");
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
            newn = new node(no);

            newn.data = no;
            newn.next = null;
            newn.prev = null;

            temp = this.first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;

            this.iCount++;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : DeleteFirst
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////
    public void DeleteFirst()
    {
        if(this.first == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.first = this.first.next;

            this.first.prev = this.last;
            this.last.next = this.first;
        }
        System.gc();
        this.iCount--;
    }
/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : DeleteLast
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////
    public void DeleteLast()
    {
        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.last = this.last.prev;

            this.last.next = this.first;
            this.first.prev = this.last;
        }
        System.gc();
        this.iCount--;
    }
/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : DeleteAtPos
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////  
    public void DeleteAtPos(int pos)
    {
        node temp = null;
        node target = null;
        int iCnt = 0;

        if(pos < 1 || pos > this.iCount)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            target = temp.next;

            temp.next = target.next;
            target.next.prev = temp;

            this.iCount--;
        }
        System.gc();
    }
/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : Display
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////
    public void Display()
    {
        if(this.first == null)
        {
            System.out.println("Linked List is Empty");
            return;
        }

        node temp = this.first;

        System.out.print("<=>");
        do
        {
            System.out.print("| "+temp.data+" | <=> ");
            temp = temp.next;
        }while(temp != this.first);

        System.out.print("\n");
    }
/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : Count
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////
    public int Count()
    {
        return this.iCount;
    }
}

/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Class   : Program448
/// Description : Main Function Call the All Function CallByValue & CallByAddress
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////

class program449
{
    public static void main(String A[])
    {
        DoublyCL obj = null;
        int iRet = 0;

        obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.DeleteAtPos(4);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
    
        // Important for memory deallocation 
        obj = null;
        System.gc();
    }
}
/*
Object of DoublyCL gets created.
<=>| 11 | <=> | 21 | <=> | 51 | <=>
Number of nodes are : 3
<=>| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of nodes are : 6
<=>| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of nodes are : 5
<=>| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>
Number of nodes are : 4
<=>| 21 | <=> | 51 | <=> | 101 | <=> | 105 | <=> | 111 | <=>
Number of nodes are : 5
<=>| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>
Number of nodes are : 4
*/