"""
Task: Implement a stack that supports getMin() in O(1) time

Time Complexity: push/pop/top/getMin O(1)
Space Complexity: O(n)
"""

class MinStack:
    def __init__(self):
        self.s = []
        self.mins = []

    def push(self, x: int):
        self.s.append(x)
        if not self.mins or x <= self.mins[-1]:
            self.mins.append(x)

    def pop(self):
        if not self.s:
            raise IndexError('pop from empty stack')
        val = self.s.pop()
        if val == self.mins[-1]:
            self.mins.pop()
        return val

    def top(self):
        if not self.s:
            raise IndexError('top from empty stack')
        return self.s[-1]

    def get_min(self):
        if not self.mins:
            raise IndexError('min from empty stack')
        return self.mins[-1]


if __name__ == '__main__':
    ms = MinStack()
    ms.push(3)
    ms.push(2)
    ms.push(4)
    print(ms.get_min())
    ms.pop()
    print(ms.get_min())
