"""
Task: Convert infix expression to prefix using a stack

Time Complexity: O(n)
Space Complexity: O(n)
"""

def prec(c: str) -> int:
    if c in '+-': return 1
    if c in '*/': return 2
    if c == '^': return 3
    return 0


def infix_to_prefix(infix: str) -> str:
    s = infix[::-1]
    s = s.replace('(', '#').replace(')', '(').replace('#', ')')

    out = []
    st = []
    for c in s:
        if c.isalnum(): out.append(c)
        elif c == '(':
            st.append(c)
        elif c == ')':
            while st and st[-1] != '(':
                out.append(st.pop())
            if st: st.pop()
        elif c.isspace():
            continue
        else:
            while st and ((prec(st[-1]) > prec(c)) or (prec(st[-1]) == prec(c) and c != '^')):
                out.append(st.pop())
            st.append(c)
    while st: out.append(st.pop())
    return ''.join(out[::-1])

if __name__ == '__main__':
    s = '(a-b/c)*(a/k-l)'
    print(infix_to_prefix(s))
