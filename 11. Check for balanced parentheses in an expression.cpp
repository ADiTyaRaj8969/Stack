/*
 Task: Check for balanced parentheses in an expression
*/

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string& s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.empty())
                return false;
            char t = st.top();
            st.pop();
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '['))
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s = "{[()]}";
    cout << boolalpha << isBalanced(s) << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
