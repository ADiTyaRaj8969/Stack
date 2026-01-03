/*
 Task: Convert infix expression to prefix using a stack
*/

#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

string infixToPrefix(string infix)
{
    // Reverse infix, swap parentheses, convert to postfix, then reverse result
    reverse(infix.begin(), infix.end());
    for (char& c : infix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    stack<char> st;
    string out;
    for (char c : infix)
    {
        if (isalnum(c))
            out.push_back(c);
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                out.push_back(st.top());
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else if (isspace(c))
            continue;
        else
        {
            while (!st.empty() &&
                   ((prec(st.top()) > prec(c)) || (prec(st.top()) == prec(c) && c != '^')))
            {
                out.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        out.push_back(st.top());
        st.pop();
    }
    reverse(out.begin(), out.end());
    return out;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPrefix(s) << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
