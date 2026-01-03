/*
 Task: Convert infix expression to postfix using a stack
*/

#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& exp)
{
    stack<char> st;
    string out;
    for (char c : exp)
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
            while (!st.empty() && prec(st.top()) >= prec(c))
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
    return out;
}

int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(s) << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
