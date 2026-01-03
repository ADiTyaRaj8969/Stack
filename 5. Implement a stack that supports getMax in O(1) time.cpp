/*
 Task: Implement a stack that supports getMax() in O(1) time
*/

#include <bits/stdc++.h>
using namespace std;

class MaxStack
{
   public:
    void push(int x)
    {
        s.push(x);
        if (maxs.empty() || x >= maxs.top())
            maxs.push(x);
    }
    bool pop(int& out)
    {
        if (s.empty())
            return false;
        out = s.top();
        if (out == maxs.top())
            maxs.pop();
        s.pop();
        return true;
    }
    int top() const
    {
        if (s.empty())
            throw runtime_error("empty");
        return s.top();
    }
    int getMax() const
    {
        if (maxs.empty())
            throw runtime_error("empty");
        return maxs.top();
    }
    bool empty() const { return s.empty(); }

   private:
    stack<int> s, maxs;
};

int main()
{
    MaxStack ms;
    ms.push(3);
    ms.push(7);
    ms.push(5);
    cout << ms.getMax() << "\n";
    int v;
    ms.pop(v);
    cout << ms.getMax() << "\n";
    return 0;
}

// Time Complexity: push/pop/top/getMax O(1)
// Space Complexity: O(n)
