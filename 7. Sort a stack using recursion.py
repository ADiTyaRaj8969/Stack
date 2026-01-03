"""
Task: Sort a stack using recursion

Time Complexity: O(n^2)
Space Complexity: O(n)
"""

def sorted_insert(s: list, x: int):
    if not s or x > s[-1]:
        s.append(x)
        return
    t = s.pop()
    sorted_insert(s, x)
    s.append(t)


def sort_stack(s: list):
    if not s:
        return
    t = s.pop()
    sort_stack(s)
    sorted_insert(s, t)


if __name__ == '__main__':
    s = [3,1,2]
    sort_stack(s)
    print(s)
