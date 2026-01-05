/*
 Task: Largest Rectangle in Histogram problem
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(const vector<int>& heights)
{
    int n = heights.size();
    stack<int> st;
    int maxA = 0;
    for (int i = 0; i <= n; ++i)
    {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && h < heights[st.top()])
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxA = max(maxA, height * width);
        }
        st.push(i);
    }
    return maxA;
}

int main()
{
    vector<int> h = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(h) << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
