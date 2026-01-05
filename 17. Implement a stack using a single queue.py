"""
Task: Implement a stack using a single queue

Time Complexity: push O(n), pop O(1)
Space Complexity: O(n)
"""

from collections import deque

class StackSingleQueue:
    def __init__(self):
        self.q = deque()

    def push(self, x: int):
        self.q.append(x)
        for _ in range(len(self.q)-1):
            self.q.append(self.q.popleft())

    def pop(self):
        if not self.q:
            raise IndexError('pop from empty stack')
        return self.q.popleft()

    def top(self):
        if not self.q:
            raise IndexError('top from empty stack')
        return self.q[0]

    def is_empty(self):
        return not self.q

if __name__ == '__main__':
    s = StackSingleQueue()
    s.push(1)
    s.push(2)
    print(s.pop())
    print(s.top())
