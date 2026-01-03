/*
 Task: Sort a stack using recursion
*/

#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>& s, int x)
{
    if (s.empty() || x > s.top())
    {
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(t);
}

void sortStack(stack<int>& s)
{
    if (s.empty())
        return;
    int t = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, t);
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(2);
    sortStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
