"""
Task: Implement Min Stack with space optimization

Time Complexity: push/pop/top/getMin O(1)
Space Complexity: O(n) but optimized
"""

class MinStackOpt:
    def __init__(self):
        self.st = []
        self.min_val = None

    def push(self, x: int):
        if not self.st:
            self.st.append(x)
            self.min_val = x
        else:
            if x < self.min_val:
                # store coded value
                self.st.append(2*x - self.min_val)
                self.min_val = x
            else:
                self.st.append(x)

    def pop(self):
        if not self.st:
            raise IndexError('pop from empty stack')
        t = self.st.pop()
        if t < self.min_val:
            orig = self.min_val
            self.min_val = 2*self.min_val - t
            return orig
        else:
            return t

    def top(self):
        if not self.st:
            raise IndexError('top from empty stack')
        t = self.st[-1]
        return self.min_val if t < self.min_val else t

    def get_min(self):
        if not self.st:
            raise IndexError('min from empty stack')
        return self.min_val

if __name__ == '__main__':
    ms = MinStackOpt()
    ms.push(3)
    ms.push(2)
    ms.push(1)
    print(ms.get_min())
    ms.pop()
    print(ms.get_min())
