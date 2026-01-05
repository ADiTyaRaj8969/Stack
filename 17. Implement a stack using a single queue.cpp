/*
 Task: Implement a stack using a single queue
*/

#include <bits/stdc++.h>
using namespace std;

class StackSingleQueue
{
   public:
    void push(int x)
    {
        q.push(x);
        int sz = q.size();
        while (sz > 1)
        {
            q.push(q.front());
            q.pop();
            --sz;
        }
    }
    bool pop(int& out)
    {
        if (q.empty())
            return false;
        out = q.front();
        q.pop();
        return true;
    }
    bool isEmpty() const { return q.empty(); }
    int top() const
    {
        if (q.empty())
            throw runtime_error("empty");
        return q.front();
    }

   private:
    queue<int> q;
};

int main()
{
    StackSingleQueue s;
    s.push(1);
    s.push(2);
    int v;
    if (s.pop(v))
        cout << v << "\n";
    cout << s.top() << "\n";
    return 0;
}

// Time Complexity: push O(n), pop O(1)
// Space Complexity: O(n)
