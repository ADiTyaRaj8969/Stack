"""
Task: Design a stack that can return the middle element in O(1)

Time Complexity: push/pop/find_middle O(1)
Space Complexity: O(n)
"""

class DLLNode:
    def __init__(self, val: int):
        self.val = val
        self.prev = None
        self.next = None

class MidStack:
    def __init__(self):
        self.head = None
        self.mid = None
        self.sz = 0

    def push(self, x: int):
        n = DLLNode(x)
        n.next = self.head
        if self.head:
            self.head.prev = n
        self.head = n
        self.sz += 1
        if self.sz == 1:
            self.mid = n
        elif self.sz % 2 == 0:
            self.mid = self.mid.prev

    def pop(self):
        if not self.head:
            raise IndexError('pop from empty stack')
        val = self.head.val
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        self.sz -= 1
        if self.sz == 0:
            self.mid = None
        elif self.sz % 2 == 1:
            self.mid = self.mid.next
        return val

    def find_middle(self) -> int:
        if not self.mid:
            raise IndexError('middle from empty stack')
        return self.mid.val

    def delete_middle(self):
        if not self.mid:
            raise IndexError('delete middle from empty stack')
        m = self.mid
        val = m.val
        if m.prev: m.prev.next = m.next
        if m.next: m.next.prev = m.prev
        if m == self.head: self.head = m.next
        self.sz -= 1
        # recompute midpoint for simplicity
        cur = self.head
        idx = 0
        target = self.sz // 2
        while cur and idx < target:
            cur = cur.next
            idx += 1
        self.mid = cur
        return val

if __name__ == '__main__':
    s = MidStack()
    s.push(1)
    s.push(2)
    s.push(3)
    s.push(4)
    print('middle:', s.find_middle())
    print('deleted:', s.delete_middle(), 'new middle:', s.find_middle())
