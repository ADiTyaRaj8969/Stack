"""
Task: Largest Rectangle in Histogram problem

Time Complexity: O(n)
Space Complexity: O(n)
"""

def largest_rectangle_area(heights):
    n = len(heights)
    st = []
    maxA = 0
    for i in range(n+1):
        h = 0 if i==n else heights[i]
        while st and h < heights[st[-1]]:
            height = heights[st.pop()]
            width = i if not st else i - st[-1] - 1
            maxA = max(maxA, height*width)
        st.append(i)
    return maxA

if __name__ == '__main__':
    print(largest_rectangle_area([2,1,5,6,2,3]))
