/*
 Task: Stock span problem using stack
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(const vector<int>& prices)
{
    int n = prices.size();
    vector<int> span(n);
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && prices[st.top()] <= prices[i]) st.pop();
        span[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return span;
}

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (auto x : stockSpan(prices)) cout << x << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
