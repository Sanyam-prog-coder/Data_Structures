// Singly Circular

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

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

/////////////////////////////////////////////////////////////////////////////////////
/// 
/// Class       : SinglyCL
/// Description : Constructer and Destructer
/// Auther  : Sanyam BhupendraKmar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////
  
class SinglyCL
{
    private node first;
    private node last;
    
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL gets created.");
        
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

        if(this.first == null)
        {
            this.first = newn;
            this.last = newn;

            newn.next = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
            this.last.next = newn;
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

        newn = new node(no);

        newn.data = no;
        newn.next = null;

        if(this.first == null)
        {
            this.first = newn;
            this.last = newn;

            newn.next = newn;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
            this.last.next = this.first;
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
        if(pos < 1 || pos > this.iCount + 1)
        {
            System.err.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount +  1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = null;
            newn = new node(no);

            int iCnt = 0;
            newn.data = no;
            newn.next = null;

            node temp = this.first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
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
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            node temp = null;
            temp = new node(iCount);

            this.first = this.first.next;

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
        if (this.first == null && this.last == null)
        {
            return;
        }
        else if (this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            node temp = first;

            while (temp.next != last)
            {
                temp = temp.next;
            }

            this.last = temp;
            this.last.next = first;
        }
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
        if(pos < 1 || pos > this.iCount)
        {
            System.out.println("Invalid Position");
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
            node temp = this.first;
            int iCnt = 0;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            node target = temp.next;
            temp.next = target.next;
            
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
        System.out.print("->");

        do
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;
        }while(temp != first);

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
/// Class   : Program447
/// Description : Main Function Call the All Function CallByValue & CallByAddress
/// Auther  : Sanyam BhupendraKumar Ravne
/// Date    : 29/12/2025
/// 
/////////////////////////////////////////////////////////////////////////////////////

class program447
{
    public static void main(String A[])
    {
        SinglyCL obj = null;
        int iRet = 0;

        obj = new SinglyCL();

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
->| 11 |->| 21 |->| 51 |->
Number of nodes are : 3
->| 11 |->| 21 |->| 51 |->| 101 |->| 111 |->| 121 |->
Number of nodes are : 6
->| 21 |->| 51 |->| 101 |->| 111 |->| 121 |->
Number of nodes are : 5
->| 21 |->| 51 |->| 101 |->| 111 |->
Number of nodes are : 4
->| 21 |->| 51 |->| 101 |->| 105 |->| 111 |->
Number of nodes are : 5
->| 21 |->| 51 |->| 101 |->| 111 |->
Number of nodes are : 4
*/