"""
Task: Implement a stack using multiple queues

Time Complexity: push O(1), pop/top O(n)
Space Complexity: O(n)
"""

from collections import deque

class StackMultiQueue:
    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x: int):
        self.q1.append(x)

    def pop(self):
        if not self.q1:
            raise IndexError('pop from empty stack')
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        val = self.q1.popleft()
        self.q1, self.q2 = self.q2, self.q1
        return val

    def top(self):
        if not self.q1:
            raise IndexError('top from empty stack')
        while len(self.q1) > 1:
            self.q2.append(self.q1.popleft())
        val = self.q1[0]
        self.q2.append(self.q1.popleft())
        self.q1, self.q2 = self.q2, self.q1
        return val

    def is_empty(self):
        return not self.q1

if __name__ == '__main__':
    s = StackMultiQueue()
    s.push(1)
    s.push(2)
    print(s.pop())
    print(s.top())
