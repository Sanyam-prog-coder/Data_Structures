class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

class SinglyCL:
    
    # Done
    def __init__(self):
        print("Object of SinglyCL gets Created.")
        self.first = None
        self.last = None
        self.iCount = 0
    # Done
    def InsertFirst(self,no):
        newn = Node(no)

        if self.first == None:
            self.first = newn
            self.last = newn
        else:
            newn.next = self.first
            self.first = newn
            self.last.next = newn

        self.iCount = self.iCount + 1

    # Done
    def InsertLast(self, no):
        newn = Node(no)

        if(self.first == None):
            self.first = newn
            self.last = newn

            newn.next = newn
        else:
            self.last.next = newn
            self.last = newn
            self.last.next = self.first

        self.iCount = self.iCount + 1
    
    # Done
    def InsertAtPos(self, no, pos):

        if(pos < 1 or pos > self.iCount + 1):
            print("Invalid Positioin")
            return
        
        if(pos == 1):
            self.InsertFirst(no)
        elif(pos == self.iCount + 1):
            self.InsertLast(no)
        else:
            newn = Node(no)

            newn.data = no
            newn.next = None

            temp = self.first

            for i in range(1, pos - 1):
                temp = temp.next

            newn.next = temp.next
            temp.next = newn

            self.iCount = self.iCount + 1

    # Done
    def DeleteFirst(self):
        if(self.first == None):
            return
        elif(self.first == self.last):
            del self.first
            self.first = None
            self.last = None
        else:
            temp = self.first

            self.first = self.first.next
            del temp

            self.last.next = self.first
        
        self.iCount = self.iCount - 1

    # Done
    def DeleteLast(self):
        if(self.first == None):
            return
        elif(self.first == self.last):
            del self.first
            self.first = None
            self.last = None
        else:
            temp = self.first

            while temp.next is not self.last:
                temp = temp.next
            
            del self.last
            self.last = temp
            self.last.next = self.first

        self.iCount = self.iCount - 1

    # Done
    def DeleteAtPos(self, pos):
        if(pos < 1 or pos > self.iCount):
            print("Invalid Position")
            return
        
        if(pos == 1):
            self.DeleteFirst()
        elif(pos == self.iCount):
            self.DeleteLast()
        else:
            temp = self.first

            for i in range(1, pos - 1):
                temp = temp.next

            target = temp.next
            temp.next = target.next
            del target

            self.iCount = self.iCount - 1

    # Done
    def Display(self):

        if(self.first == None):
            print("Linked List is Empty")
            return
        
        temp = self.first

        print("->",end=" ")

        while True:
            print("| ",temp.data," |->",end= " ")
            temp = temp.next
            if temp == self.first:
                break

        print()

    # Done
    def Count(self):
        return self.iCount

def main():
    SCL = SinglyCL()

    SCL.InsertFirst(51)
    SCL.InsertFirst(21)
    SCL.InsertFirst(11)
    
    print("Elemets of LinkedList Are : ")
    SCL.Display()

    print("Number of Elements in LinkeList are : ",SCL.Count())

    SCL.InsertLast(101)
    SCL.InsertLast(111)

    SCL.Display()

    print("Number of Elements in LinkeList are : ",SCL.Count())

    SCL.InsertAtPos(75,3)

    SCL.Display()

    print("Number of Elements in LinkeList are : ",SCL.Count())    

    SCL.DeleteFirst()

    SCL.Display()

    print("Number of Elements in LinkeList are : ",SCL.Count())

    SCL.DeleteLast()

    SCL.Display()

    print("Number of Elements in LinkeList are : ",SCL.Count()) 

    SCL.DeleteAtPos(2)

    SCL.Display()

    print("Number of Elements in LinkeList are : ",SCL.Count())    

if __name__ == "__main__":
    main()

"""
Object of SinglyCL gets Created.
Elemets of LinkedList Are : 
-> |  11  |-> |  21  |-> |  51  |-> 
Number of Elements in LinkeList are :  3
-> |  11  |-> |  21  |-> |  51  |-> |  101  |-> |  111  |-> 
Number of Elements in LinkeList are :  5
-> |  11  |-> |  21  |-> |  75  |-> |  51  |-> |  101  |-> |  111  |-> 
Number of Elements in LinkeList are :  6
-> |  21  |-> |  75  |-> |  51  |-> |  101  |-> |  111  |-> 
Number of Elements in LinkeList are :  5
-> |  21  |-> |  75  |-> |  51  |-> |  101  |-> 
Number of Elements in LinkeList are :  4
-> |  21  |-> |  51  |-> |  101  |-> 
Number of Elements in LinkeList are :  3

"""