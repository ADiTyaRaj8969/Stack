"""
Task: Reverse a stack using recursion

Time Complexity: O(n^2)
Space Complexity: O(n)
"""

def insert_at_bottom(s: list, x: int):
    if not s:
        s.append(x)
        return
    t = s.pop()
    insert_at_bottom(s, x)
    s.append(t)


def reverse_stack(s: list):
    if not s:
        return
    t = s.pop()
    reverse_stack(s)
    insert_at_bottom(s, t)


if __name__ == '__main__':
    s = [1,2,3]
    reverse_stack(s)
    print(s)
