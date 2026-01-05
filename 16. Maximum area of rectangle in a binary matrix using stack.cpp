/*
 Task: Maximum area of rectangle in a binary matrix using stack
*/

#include <bits/stdc++.h>
using namespace std;

int maxAreaInBinaryMatrix(vector<vector<int>>& mat)
{
    if (mat.empty())
        return 0;
    int n = mat.size(), m = mat[0].size();
    vector<int> heights(m, 0);
    int best = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) heights[j] = mat[i][j] ? heights[j] + 1 : 0;
        best = max(best, [ & ](const vector<int>&h){ // compute largest rectangle in histogram
            int res=0; stack<int> st; int sz=h.size();
            for(int k=0;k<=sz;++k){ int hh = (k==sz)?0:h[k]; while(!st.empty() && hh < h[st.top()]){ int height=h[st.top()]; st.pop(); int width = st.empty()?k:k-st.top()-1; res=max(res,height*width);} st.push(k);} return res; }(heights));
    }
    return best;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    cout << maxAreaInBinaryMatrix(mat) << "\n";
    return 0;
}

// Time Complexity: O(n*m)
// Space Complexity: O(m)
