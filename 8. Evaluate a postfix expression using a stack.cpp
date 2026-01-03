/*
 Task: Evaluate a postfix expression using a stack
*/

#include <bits/stdc++.h>
using namespace std;

int evalPostfix(const string& expr)
{
    stack<int> st;
    istringstream iss(expr);
    string token;
    while (iss >> token)
    {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            st.push(stoi(token));
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (token == "+")
                st.push(a + b);
            else if (token == "-")
                st.push(a - b);
            else if (token == "*")
                st.push(a * b);
            else if (token == "/")
                st.push(a / b);
        }
    }
    return st.top();
}

int main()
{
    string expr = "2 3 1 * + 9 -";
    cout << evalPostfix(expr) << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
