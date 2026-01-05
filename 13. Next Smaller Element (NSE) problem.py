"""
Task: Next Smaller Element (NSE) problem

Time Complexity: O(n)
Space Complexity: O(n)
"""

def next_smaller(a):
    n = len(a)
    res = [-1] * n
    st = []
    for i, val in enumerate(a):
        while st and val < a[st[-1]]:
            res[st.pop()] = val
        st.append(i)
    return res

if __name__ == '__main__':
    print(next_smaller([4,8,5,2,25]))
