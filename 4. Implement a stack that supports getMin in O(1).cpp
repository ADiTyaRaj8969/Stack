/*
 Task: Implement a stack that supports getMin() in O(1) time
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
   public:
    void push(int x)
    {
        s.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
    }
    bool pop(int& out)
    {
        if (s.empty())
            return false;
        out = s.top();
        if (out == mins.top())
            mins.pop();
        s.pop();
        return true;
    }
    int top() const
    {
        if (s.empty())
            throw runtime_error("empty");
        return s.top();
    }
    int getMin() const
    {
        if (mins.empty())
            throw runtime_error("empty");
        return mins.top();
    }
    bool empty() const { return s.empty(); }

   private:
    stack<int> s, mins;
};

int main()
{
    MinStack ms;
    ms.push(3);
    ms.push(2);
    ms.push(4);
    cout << ms.getMin() << "\n";
    int v;
    ms.pop(v);
    cout << ms.getMin() << "\n";
    return 0;
}

// Time Complexity: push/pop/top/getMin O(1)
// Space Complexity: O(n)
