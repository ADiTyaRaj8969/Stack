"""
Task: Convert infix expression to postfix using a stack

Time Complexity: O(n)
Space Complexity: O(n)
"""

def prec(c: str) -> int:
    if c in '+-': return 1
    if c in '*/': return 2
    return 0


def infix_to_postfix(exp: str) -> str:
    st = []
    out = []
    for c in exp:
        if c.isalnum():
            out.append(c)
        elif c == '(':
            st.append(c)
        elif c == ')':
            while st and st[-1] != '(':
                out.append(st.pop())
            if st: st.pop()
        elif c.isspace():
            continue
        else:
            while st and prec(st[-1]) >= prec(c):
                out.append(st.pop())
            st.append(c)
    while st:
        out.append(st.pop())
    return ''.join(out)

if __name__ == '__main__':
    s = 'a+b*(c^d-e)^(f+g*h)-i'
    print(infix_to_postfix(s))
