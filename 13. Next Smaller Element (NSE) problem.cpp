/*
 Task: Next Smaller Element (NSE) problem
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(const vector<int>& a)
{
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> st;  // store indices
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            res[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main()
{
    vector<int> a = {4, 8, 5, 2, 25};
    for (int x : nextSmaller(a)) cout << x << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
