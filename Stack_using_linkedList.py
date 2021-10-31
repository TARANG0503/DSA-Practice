class Node:
    def __init__(self , data):
        self.data = data 
        self.next = None

class Stack:
    def __init__(self):
        self.head = None
        self.count = 0
        

    def push(self,element):
        newnode = Node(int(element))
        if self.head is None:
            self.head = newnode
            self.count += 1 
            self.tail = newnode
        else :
            newnode.next = self.head 
            self.head = newnode
            self.count += 1
        # return self.head
    def pop(self):
        if self.isEmpty() is True:
            print("!!!!!!!!!!!!! stack is empty !!!!!!!!!!!")
            return 
        data = self.head.data
        self.head = self.head.next
        self.count -= 1
        return data
    def size(self):
        return self.count
    def isEmpty(self):
        return self.size() == 0

    def top(self):
        if self.isEmpty() is True:
            print("!!!!!!! Stack is empty !!! ")
            return
            
        return self.head.data


def reverseStack(s1, s2):
    if len(s1) <= 1 :
        return
    while len(s1) != 1 : 
        ele = s1.pop()
        s2.append(ele)
    lastElement = s1.pop()
    while len(s2) != 0 :
        ele = s2.pop()
        s1.append(ele)
    reverseStack(s1,s2)
    s1.append(lastElement)

n = int(input())
s1 = [int(ele) for ele in input().split()]
s2 = []
reverseStack(s1, s2)
while (len(s1) != 0 ):
    print(s1.pop(), end=" ")