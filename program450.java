// Doubly Linear

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
/// Class       : DoublyLL
/// Description : Constructer and Destructer
/// Auther  : Sanyam BhupendraKmar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////

class DoublyLL
{
    private node first;
    
    private int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created.");
        
        this.first = null;
        
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

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            newn.next = this.first;
            this.first.prev = newn;
            this.first = newn;
        }
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
        node temp = null;

        newn = new node(no);

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
            temp.prev = temp;
        }
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
        node newn = null;
        node temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > this.iCount + 1)
        {
            System.out.print("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == this.iCount + 1)
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
            newn.prev = temp;

            newn.next.prev = newn;
            temp.next = newn;

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
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            node temp = this.first;

            this.first = this.first.next;
            this.first.prev = null;
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
        node temp  = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            temp = this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
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
        node temp = this.first;

        System.out.print("null <=>");

        while(temp != null)
        {
            System.out.print("| "+temp.data+" | <=>");
            temp = temp.next;
        }
        System.out.println(" null");
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

class program450
{
    public static void main(String A[])
    {
        DoublyLL obj = null;
        int iRet = 0;

        obj = new DoublyLL();

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
Object of DoublyLL gets created.
null <=>| 11 | <=>| 21 | <=>| 51 | <=> null
Number of nodes are : 3
null <=>| 11 | <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>| 121 | <=> null
Number of nodes are : 6
null <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=>| 121 | <=> null
Number of nodes are : 5
null <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=> null
Number of nodes are : 4
null <=>| 21 | <=>| 51 | <=>| 101 | <=>| 105 | <=>| 111 | <=> null
Number of nodes are : 5
null <=>| 21 | <=>| 51 | <=>| 101 | <=>| 111 | <=> null
Number of nodes are : 4
*/