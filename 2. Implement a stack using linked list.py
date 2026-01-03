"""
Task: Implement a stack using linked list

Time Complexity: push/pop/top O(1)
Space Complexity: O(n)
"""

class Node:
    def __init__(self, val: int):
        self.val = val
        self.next = None

class LinkedListStack:
    def __init__(self):
        self.head = None

    def push(self, x: int):
        n = Node(x)
        n.next = self.head
        self.head = n

    def pop(self):
        if not self.head:
            raise IndexError('pop from empty stack')
        val = self.head.val
        self.head = self.head.next
        return val

    def top(self):
        if not self.head:
            raise IndexError('top from empty stack')
        return self.head.val

    def is_empty(self):
        return self.head is None


if __name__ == '__main__':
    s = LinkedListStack()
    s.push(10)
    s.push(20)
    print(s.pop())
    print(s.top())
