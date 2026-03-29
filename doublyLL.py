class Node:
    def __init__(self,value):
        self.data = value
        self.next = None
        self.prev = None
    
class DoublyLL:
    def __init__(self):
        print("Object gets created")
        self.first = None
        self.iCount = 0
        
    def InsertFirst(self, no):
        newn = Node(no)

        if(self.first == None):
            self.first = newn
        else:
            newn.next = self.first
            self.first.prev = newn
            self.first = newn

        self.iCount = self.iCount + 1

    def InsertLast(self, no):
        newn = Node(no)

        if(self.first == None):
            self.first = newn
        else:
            temp = self.first

            while temp.next is not None:
                temp = temp.next
            
            temp.next = newn
            temp.prev = temp

        self.iCount = self.iCount + 1

    def InsertAtPos(self, no, pos):
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

            for i in range(1,pos - 1):
                temp = temp.next
            
            newn.next = temp.next
            newn.prev = temp

            newn.next.prev = newn
            temp.next = newn

            self.iCount = self.iCount + 1

    def DeleteFirst(self):
        if(self.first == None):
            return
        elif(self.first.next == None):
            self.first = None
        else:
            temp = self.first

            self.first = self.first.next
            self.first.prev = None

        self.iCount = self.iCount - 1

    def DeleteLast(self):
        if(self.first == None):
            return
        elif(self.first.next == None):
            self.first = None
        else:
            temp = self.first

            while temp.next.next is not None:
                temp = temp.next
            
            temp.next = None

            self.iCount = self.iCount - 1

    def DeleteAtPos(self, pos):
        if(pos < 1 or pos > self.iCount):
            print("Invalid position")
            return
        
        if(pos == 1):
            self.DeleteFirst()
        elif(pos == self.iCount):
            self.DeleteLast()
        else:
            temp = self.first

            for i in range(1,pos - 1):
                temp = temp.next

            target = temp.next

            temp.next = target.next
            target.next.prev = temp

            self.iCount = self.iCount - 1

    def Display(self):
        if(self.first == None):
            print("Linkedlist is empty")
            return
        
        temp = self.first

        print("None <=>",end=" ")

        while(temp != None):
            print("| ",temp.data," | <=>",end=" ")
            temp = temp.next

        print("None")

    def Count(self):
        return self.iCount
 
def main():
    DLL = DoublyLL()

    DLL.InsertFirst(101)
    DLL.InsertFirst(51)
    DLL.InsertFirst(21)
    DLL.InsertFirst(11)

    DLL.Display()

    print("Number of Elements in Linkedlist is : ",DLL.Count())

    DLL.InsertLast(111)
    DLL.InsertLast(121)

    DLL.Display()

    print("Number of Elements in Linkedlist is : ",DLL.Count())

    DLL.InsertAtPos(75,4)

    DLL.Display()

    print("Number of Elements in Linkedlist is : ",DLL.Count())

    DLL.DeleteFirst()

    DLL.Display()

    print("Number of Elements in Linkedlist is : ",DLL.Count())

    DLL.DeleteLast()

    DLL.Display()

    print("Number of Elements in Linkedlist is : ",DLL.Count())

    DLL.DeleteAtPos(3)

    DLL.Display()

    print("Number of Elements in Linkedlist is : ",DLL.Count())

if __name__ == "__main__":
    main()