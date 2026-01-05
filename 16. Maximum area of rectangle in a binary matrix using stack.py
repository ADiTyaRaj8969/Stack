"""
Task: Maximum area of rectangle in a binary matrix using stack

Time Complexity: O(n*m)
Space Complexity: O(m)
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


def max_area_in_binary_matrix(mat):
    if not mat: return 0
    n = len(mat); m = len(mat[0])
    heights = [0]*m
    best = 0
    for i in range(n):
        for j in range(m):
            heights[j] = heights[j]+1 if mat[i][j] else 0
        best = max(best, largest_rectangle_area(heights))
    return best

if __name__ == '__main__':
    mat = [[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]
    print(max_area_in_binary_matrix(mat))
