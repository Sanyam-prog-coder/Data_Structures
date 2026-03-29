class Node:
    def __init__(self, value):
        self.data = value
        self.next = None
        self.prev = None

class DoublyCL:
    def __init__(self):
        print("Object gets created")
        self.first = None
        self.last = None
        self.iCount = 0

    def InsertFirst(self,no):
        newn = Node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn
        else:
            newn.next = self.first
            self.first.prev = newn
            self.first = newn

        self.last.next = self.first
        self.first.prev = self.last
        self.iCount = self.iCount + 1

    def InsertLast(self,no):
        newn = Node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn
        else:
            self.last.next = newn
            newn.prev = self.last
            self.last = newn
        
        self.last.next = self.first
        self.first.prev = self.last

        self.iCount = self.iCount + 1

    def InsertAtPos(self,no,pos):
        if(pos < 1 or pos > self.iCount + 1):
            print("Invalid Position")
            return
        
        if(pos == 1):
            self.InsertFirst(no)
        elif(pos == self.iCount + 1):
            self.InsertLast(no)
        else:
            newn = Node(no)

            temp = self.first

            for i in range(1, pos -1):
                temp = temp.next

            newn.next = temp.next
            newn.next.prev = newn

            temp.next = newn
            newn.prev = temp

            self.iCount = self.iCount + 1

    def DeleteFirst(self):
        if(self.first == None):
            return
        elif(self.first == self.last):
            del self.first
            self.first = None
            self.last = None
        else:
            self.first = self.first.next
            del self.first.prev

            self.first.prev = self.last
            self.last.next = self.first

        self.iCount = self.iCount - 1

    def DeleteLast(self):
        if(self.first == None or self.last == None):
            return
        elif(self.first == self.last):
            del self.first
            self.first = None
            self.last = None
        else:
            self.last = self.last.prev
            del self.last.next

            self.last.next = self.first
            self.first.prev = self.last

        self.iCount = self.iCount - 1

    def DeleteAtPos(self,pos):
        if(pos < 1 or pos > self.iCount):
            print("Invalid Position")
            return
        
        if(pos == 1):
            self.DeleteFirst()
        elif(pos == self.iCount):
            self.DeleteLast()
        else:
            temp = self.first

            for i in range(1, pos -1):
                temp = temp.next

            target = temp.next

            temp.next = target.next
            target.next.prev = temp

            del target

            self.iCount = self.iCount - 1

    def Display(self):
        if(self.first == None):
            print("Linkedlist is empty")
            return
        
        temp = self.first

        print("<=>",end=" ")

        while True:
            print("| ",temp.data," | <=>",end=" ")
            temp = temp.next

            if temp == self.first:
                break

        print()

    def Count(self):
        return self.iCount

def main():
    DCL = DoublyCL()

    DCL.InsertFirst(101)
    DCL.InsertFirst(51)
    DCL.InsertFirst(21)
    DCL.InsertFirst(11)

    DCL.Display()

    print("Number of Elements in LinkeList are : ",DCL.Count())

    DCL.InsertLast(111)
    DCL.InsertLast(121)

    DCL.Display()

    print("Number of Elements in LinkeList are : ",DCL.Count())

    DCL.InsertAtPos(75,4)

    DCL.Display()

    print("Number of Elements in LinkeList are : ",DCL.Count())

    DCL.DeleteFirst()

    DCL.Display()

    print("Number of Elements in LinkeList are : ",DCL.Count())

    DCL.DeleteLast()

    DCL.Display()

    print("Number of Elements in LinkeList are : ",DCL.Count())

    DCL.DeleteAtPos(3)

    DCL.Display()

    print("Number of Elements in LinkeList are : ",DCL.Count())

if __name__ == "__main__":
    main()

"""
Object gets created
<=> |  11  | <=> |  21  | <=> |  51  | <=> |  101  | <=> 
Number of Elements in LinkeList are :  4
<=> |  11  | <=> |  21  | <=> |  51  | <=> |  101  | <=> |  111  | <=> |  121  | <=> 
Number of Elements in LinkeList are :  6
<=> |  11  | <=> |  21  | <=> |  51  | <=> |  75  | <=> |  101  | <=> |  111  | <=> |  121  | <=> 
Number of Elements in LinkeList are :  7
<=> |  21  | <=> |  51  | <=> |  75  | <=> |  101  | <=> |  111  | <=> |  121  | <=> 
Number of Elements in LinkeList are :  6
<=> |  21  | <=> |  51  | <=> |  75  | <=> |  101  | <=> |  111  | <=> 
Number of Elements in LinkeList are :  5
<=> |  21  | <=> |  51  | <=> |  101  | <=> |  111  | <=> 
Number of Elements in LinkeList are :  4

"""