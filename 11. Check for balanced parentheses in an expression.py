"""
Task: Check for balanced parentheses in an expression

Time Complexity: O(n)
Space Complexity: O(n)
"""

def is_balanced(s: str) -> bool:
    st = []
    pairs = {')':'(', ']':'[', '}':'{'}
    for c in s:
        if c in '([{': st.append(c)
        elif c in ')]}':
            if not st or st[-1] != pairs[c]: return False
            st.pop()
    return not st

if __name__ == '__main__':
    print(is_balanced('{[()]}'))
