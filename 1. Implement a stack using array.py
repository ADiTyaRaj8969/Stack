"""
Task: Implement a stack using array

Time Complexity: push/pop/top O(1)
Space Complexity: O(n)
"""

class ArrayStack:
    def __init__(self, capacity: int):
        self._data = [None] * capacity
        self._cap = capacity
        self._top = -1

    def push(self, x: int) -> bool:
        if self._top + 1 >= self._cap:
            return False
        self._top += 1
        self._data[self._top] = x
        return True

    def pop(self):
        if self._top < 0:
            raise IndexError("pop from empty stack")
        val = self._data[self._top]
        self._top -= 1
        return val

    def top(self):
        if self._top < 0:
            raise IndexError("top from empty stack")
        return self._data[self._top]

    def is_empty(self) -> bool:
        return self._top < 0


if __name__ == "__main__":
    s = ArrayStack(10)
    s.push(1)
    s.push(2)
    print(s.pop())
    print(s.top())
