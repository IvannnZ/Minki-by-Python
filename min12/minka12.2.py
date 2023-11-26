class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete_node(self, key):
        current_node = self.head
        if current_node and current_node.data == key:
            self.head = current_node.next
            current_node = None
            return
        prev = None
        while current_node and current_node.data != key:
            prev = current_node
            current_node = current_node.next
        if current_node is None:
            return
        prev.next = current_node.next
        current_node = None

    def print_list(self):
        current_node = self.head
        while current_node:
            print(current_node.data, end=" -> ")
            current_node = current_node.next
        print("None")

    def __iter__(self):
        return LinkedList.Iterator(self.head)

    class Iterator:
        def __init__(self, head):
            self.curr = head
            self.head = head

        def __next__(self):
            if self.curr:
                res = self.curr
                self.curr = self.curr.next
                return res.data
            else:
                raise StopIteration

        def __iter__(self):
            return self


linked_list = LinkedList()
linked_list.append(1)
linked_list.append(2)
linked_list.append(3)
linked_list.append(4)

linked_list.print_list()

linked_list.prepend(5)
linked_list.print_list()

linked_list.delete_node(3)
linked_list.print_list()


def cahin(*iters):
    for i in iters:
        for j in i:
            yield j


for i in cahin(linked_list, [4, 3, 2, 1], " IT WORKS!"):
    print(i)
