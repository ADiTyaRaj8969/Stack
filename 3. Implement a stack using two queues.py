"""
Task: Implement a stack using two queues

Time Complexity: push O(n), pop O(1)
Space Complexity: O(n)
"""

from collections import deque

class StackUsingQueues:
    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x: int):
        self.q2.append(x)
        while self.q1:
            self.q2.append(self.q1.popleft())
        self.q1, self.q2 = self.q2, self.q1

    def pop(self):
        if not self.q1:
            raise IndexError('pop from empty stack')
        return self.q1.popleft()

    def top(self):
        if not self.q1:
            raise IndexError('top from empty stack')
        return self.q1[0]

    def is_empty(self) -> bool:
        return not self.q1


if __name__ == '__main__':
    s = StackUsingQueues()
    s.push(1)
    s.push(2)
    print(s.pop())
    print(s.top())
