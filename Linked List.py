class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class Linkedlist:
    def __init__(self):
        self.head = None

    def insert_at_beg(self, data):
        node = Node(data, self.head)
        self.head = node

    def print(self):
        itr = self.head
        llstr = ''
        while itr:
            suffix = ''
            if itr.next:
                suffix = '---->'
            llstr += str(itr.data) + suffix
            itr = itr.next
        print(llstr)

    def get_length(self):
        count = 0
        itr = self.head
        while itr:
            count += 1
            itr = itr.next
        return count

    def insert_at_end(self, data):
        if self.head is None:
            self.head = Node(data, None)
            return
        itr = self.head
        while itr.next:
            itr = itr.next

        itr.next = Node(data, None)

    def insert_at(self, index, data):
        if index < 0 or index > self.get_length():
            raise Exception("Invalid Index")

        if index == 0:
            self.insert_at_beg(data)
            return

        count = 0
        itr = self.head
        while itr:
            if count == index - 1:
                node = Node(data, itr.next)
                itr.next = node
                break

            itr = itr.next
            count += 1

    def remove_at(self, index):
        if index < 0 or index > self.get_length():
            raise Exception("INVALID INDEX")

        if index == 0:
            self.head = self.head.next

        itr = self.head
        count = 0
        while itr:
            if count == index - 1:
                itr.next = itr.next.next
                break
            itr = itr.next
            count += 1

    def insert_values(self, data_list):
        self.head = None
        for data in data_list:
            self.insert_at_end(data)

    def insert_after_val(self, data_after, data_to_insert):

        if self.head is None:
            return

        if self.head.data == data_after:
            self.head.next = Node(data_to_insert, self.head.next)
            return
        # while itr:
        #     if itr.data == data_after:
        #         node = Node(data_to_insert, itr.next)
        #         itr.next = node
        #         break

        itr = self.head
        while itr:
            if itr.data == data_after:
                itr.next = Node(data_to_insert, itr.next)
                break

            itr = itr.next

    def remove_by_val(self, data_del):

        if self.head is None:
            return

        if self.head.data == data_del:
            self.head = self.head.next
            return

        itr = self.head
        while itr.next:
            if itr.next.data == data_del:
                itr.next = itr.next.next
                break
            itr = itr.next

if __name__ == '__main__':