"""
Task: Evaluate a postfix expression using a stack

Time Complexity: O(n)
Space Complexity: O(n)
"""

def eval_postfix(expr: str) -> int:
    st = []
    for token in expr.split():
        if token.lstrip('-').isdigit():
            st.append(int(token))
        else:
            b = st.pop()
            a = st.pop()
            if token == '+': st.append(a+b)
            elif token == '-': st.append(a-b)
            elif token == '*': st.append(a*b)
            elif token == '/': st.append(int(a/b))
    return st[-1]

if __name__ == '__main__':
    expr = '2 3 1 * + 9 -'
    print(eval_postfix(expr))
