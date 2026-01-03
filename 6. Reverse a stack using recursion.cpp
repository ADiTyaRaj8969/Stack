/*
 Task: Reverse a stack using recursion
*/

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(t);
}

void reverseStack(stack<int>& s)
{
    if (s.empty())
        return;
    int t = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, t);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    return 0;
}

// Time Complexity: O(n^2) due to insertAtBottom
// Space Complexity: O(n) recursion stack
