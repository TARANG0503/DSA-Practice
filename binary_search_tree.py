class Node:
    def __init__(self, data):
        self.data = data 
        self.left = None
        self.right = None
def treeInput():
        rootData = int(input())
        if rootData == -1 :
            return None
        root = Node(rootData)
        leftTree = treeInput()
        rightTree = treeInput()
        root.left = leftTree
        root.right = rightTree
        return root 


def printTree(root):
    if root is None:
        return 
    print(root.data, end=": ")
    if root.left != None:
        print("L- ",root.left.data , end=",")
    if root.right != None:
        print("R- ",root.right.data, end=",")
    print()
    printTree(root.left)
    printTree(root.right)



def search(root, x):
    if root is None:
        return False
    if root.data == x:
        return True
    if root.data > x :
        leftsearch = search(root.left, x)
        return leftsearch
    else:
        rightsearch = search(root.right, x)
        return rightsearch
    #return leftsearch or rightsearch

# print nodes lying between k1 and k2: 

def printElementBetweenK1andK2(root,k1,k2):
    if root is None:
        return 
    if root.data < k1:
        printElementBetweenK1andK2(root.right, k1,k2)
    elif root.data >k2:
        printElementBetweenK1andK2(root.left, k1,k2)
    else:
        print(root.data)
        printElementBetweenK1andK2(root.left, k1,k2)
        printElementBetweenK1andK2(root.right, k1,k2)

# create a BST from a given sorted array
def BSTfromSortedArray(arr):
    n = len(arr)
    if n == 1:
        return Node(arr[0])
    mid = n//2
    root = Node(arr[mid])
    leftSubTree = BSTfromSortedArray(arr[:mid])
    rightSubTree = BSTfromSortedArray(arr[mid+1:])
    root.left = leftSubTree
    root.right = rightSubTree
    return root

# Check if a tree given is Binary Search Tree: 
# def checkBST(root):
#     if root is None:
#         return True 
#     if root.left is None and root.right is None:
#         return True
#     elif root.left is None:
#         return checkBST(root.right)
#     elif root.right is None :
#         return checkBST(root.left)
    
#     if root.right.data < root.data:
#         return False
#     elif root.left.data >= root.data:
#         return False
#     else :
#         return True
    
#### The above solution seems to be correct i.e. we are checking left subtree's root's data with the root for each node and similarly for the right subtree. But this do have a problem
## We need to check if all the elements in the left subtree are less than the root for each node and all elements of right subtree should be greater than or equal to the root node. 
## For this we can check if max(left subtree) < root and if min(rightsubtree) > root.
def minTree(root):
    if root == None:
        return 10000
    leftMin = minTree(root.left)
    rightMin = minTree(root.right)
    return min(leftMin, rightMin, root.data)
def maxTree(root):
    if root == None:
        return -10000
    leftMax = maxTree(root.left)
    rightMax = maxTree(root.right)
    return max(leftMax, rightMax, root.data)
def checkBST(root):
    if root is None:
        return True 
    leftMax = maxTree(root.left)
    rightMin = minTree(root.right)
    if root.data > rightMin or root.data <=leftMax:
        return False
    isLeftBST = checkBST(root.left)
    isRightBST = checkBST(root.right)
    return isLeftBST and isRightBST

def isBST2(root):
    if root == None:
        return 10000, -10000, True                          # return min , max , and isBST 
    leftMin, leftMax , isLeftBST = isBST2(root.left)
    rightMin, rightMax, isRightBST = isBST2(root.right)
    minimum = min(leftMin, rightMin, root.data)
    maximum = max(leftMax, rightMax, root.data)
    isTreeBST = True
    if root.data <= leftMax or root.data > rightMin:
        isTreeBST = False
    if not isLeftBST or not isRightBST:
        isTreeBST = False 
    return minimum , maximum , isTreeBST

def isBST3(root, min_range, max_range):
    if root is None:
        return True
    if root.data < min_range or root.data > max_range:
        return False
    isLeftWithinRange = isBST3(root.left, min_range, root.data)
    isRightWithinRange = isBST3(root.right, root.data , max_range)
    return isLeftWithinRange and isRightWithinRange

def rootToNodePath(root, s):
    if root is None:
        return None
    if root.data == s:
        l = list()
        l.append(root.data)
        return l
    leftOutput = rootToNodePath(root.left,s)
    if leftOutput is not None:
        leftOutput.append(root.data)
        return leftOutput
    rightOutput = rootToNodePath(root.right, s)
    if rightOutput is not None:
        rightOutput.append(root.data)
        return rightOutput
    else :
        return None

###########################################################################
##          BST CLASS                                   ##################
###########################################################################

class BST:
    def __init__(self) -> None:
        self.root = None
        self.numNodes = 0
    
    def isPresentHelper(self, root, data):
        if root is None:
            return False
        if root.data == data:
            return True
        if root.data > data:
            return self.isPresentHelper(root.left, data)
        else:
            return self.isPresentHelper(root.right, data)
    def isPresent(self, data):
        return self.isPresentHelper(self.root, data)

    def printTreeHelper(self, root):
        if root is None:
            return None
        print(root.data, end=":")
        if root.left != None:
            print("L- " , root.left.data, end=", ")
        if root.right != None:
            print("R- ", root.right.data, end=", ")
        print()
        self.printTreeHelper(root.left)
        self.printTreeHelper(root.right)
    def printTree(self):
        return self.printTreeHelper(self.root)
    def insertHelper(self, root,data):
        if root is None:
            node = Node(data)
            return node
        if root.data > data:
            root.left = self.insertHelper(root.left, data)
            return root
        else:
            root.right = self.insertHelper(root.right, data)
            return root
    def insert(self, data):
        self.numNodes += 1
        self.root = self.insertHelper(self.root, data)

    def count(self):
        return self.numNodes
    def min(self, root):
        if root == None:
            return 100000
        if root.left == None:
            return root.data
        return self.min(root.left)
    def deleteHelper(self, root, data):
        if root is None:
            return False, None
        if root.data > data :
            deleted, newleft = self.deleteHelper(root.left, data)
            root.left = newleft
            return deleted , root
        if root.data < data:
            deleted , newright = self.deleteHelper(root.right, data)
            root.right = newright
            return deleted, root
        ## if root is leaf
        if root.left is None and root.right is None:
            return True, None
        # if root has one child
        if root.left is None:
            return True, root.right
        if root.right is None:
            return True, root.left
        # if root has two children   
        if root.data == data:
            replacement = self.min(root.right)
            root.data = replacement
            deleted, newright = self.deleteHelper(root.right, replacement)
            root.right = newright
            return True, root

    def delete(self, data):
        deleted, newroot = self.deleteHelper(self.root, data)
        if deleted:
            self.numNodes -= 1
        self.root = newroot
        return deleted
################################################################################

b = BST()
b.insert(10)
b.insert(5)
b.insert(12)
print(b.isPresent(10))
print(b.isPresent(7))
print(b.delete(4))
print(b.delete(10))
print(b.count())
b.printTree()