"""
Task: Stock span problem using stack

Time Complexity: O(n)
Space Complexity: O(n)
"""

def stock_span(prices):
    n = len(prices)
    span = [0]*n
    st = []
    for i, price in enumerate(prices):
        while st and prices[st[-1]] <= price:
            st.pop()
        span[i] = i+1 if not st else i - st[-1]
        st.append(i)
    return span

if __name__ == '__main__':
    print(stock_span([100,80,60,70,60,75,85]))
