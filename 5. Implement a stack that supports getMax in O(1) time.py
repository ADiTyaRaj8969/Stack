"""
Task: Implement a stack that supports getMax() in O(1) time

Time Complexity: push/pop/top/getMax O(1)
Space Complexity: O(n)
"""

class MaxStack:
    def __init__(self):
        self.s = []
        self.maxs = []

    def push(self, x: int):
        self.s.append(x)
        if not self.maxs or x >= self.maxs[-1]:
            self.maxs.append(x)

    def pop(self):
        if not self.s:
            raise IndexError('pop from empty stack')
        val = self.s.pop()
        if val == self.maxs[-1]:
            self.maxs.pop()
        return val

    def top(self):
        if not self.s:
            raise IndexError('top from empty stack')
        return self.s[-1]

    def get_max(self):
        if not self.maxs:
            raise IndexError('max from empty stack')
        return self.maxs[-1]


if __name__ == '__main__':
    ms = MaxStack()
    ms.push(3)
    ms.push(7)
    ms.push(5)
    print(ms.get_max())
    ms.pop()
    print(ms.get_max())
