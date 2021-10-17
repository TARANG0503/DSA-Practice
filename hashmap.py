class MapNode:
    def __init__(self,key, value):
        self.value = value
        self.key = key
        self.next = None
class Map:
    def __init__(self):
        self.bucketSize = 5
        self.buckets = [None for i in range(self.bucketSize)]
        self.count = 0
    def size(self):
        return self.count
    def getIndex(self, hashCode):
        return abs(hashCode)%self.bucketSize
        
    def insert(self, key, value):
        hashCode = hash(key)
        index = self.getIndex(hashCode)
        head = self.buckets[index]
        while head != None:
            if head.key == key:
                head.value = value
                return
            head = head.next
        newNode = MapNode(key,value)
        newNode.next = head
        self.buckets[index] = newNode
        self.count += 1
        loadFactor = self.count/self.bucketSize
        if loadFactor >= 0.7:
            self.rehash()

    def rehash(self):
        print("rehashing....")
        temp = self.buckets
        self.buckets = [None for i in range(2* self.bucketSize)]
        self.bucketSize = 2* self.bucketSize
        self.count = 0
        for head in temp:
            while head is not None:
                self.insert(head.key, head.value)
                head = head.next
        

    def getLoadFactor(self):
        return self.count/self.bucketSize


    def search(self, key):
        hashCode = hash(key)
        index = self.getIndex(hashCode)
        head = self.buckets[index]
        while head != None:
            if head.key == key:
                return head.value
            head = head.next
            return "Not found"
        return "Head becomes None"
    def delete(self, key):
        hashCode = hash(key)
        index = self.getIndex(hashCode)
        head = self.buckets[index]
        while head != None:
            if head.key == key and head.next != None:
                head.key = head.next.key
                head.value = head.next.value
                head.next = head.next.next
                self.count -= 1
                return True
            elif head.key == key:
                head = None
                self.count -= 1
                return True
            return False
    def delete2(self, key):             # basic approach: using a prev pointer to previous node
        hashCode = hash(key)
        index = self.getIndex(hashCode)
        head = self.buckets[index]
        prev = None
        while head != None:

            if head.key == key:
                if prev == None:
                    self.buckets[index] = head.next
                else:
                    prev.next = head.next
                return head.value
            prev = head
            head = head.next
        return None