/*
 Task: Implement a stack using multiple queues
*/

#include <bits/stdc++.h>
using namespace std;

// Simple approach: keep pushing to q1, for pop move all but last to q2, pop last, swap

class StackMultiQueue
{
   public:
    void push(int x) { q1.push(x); }
    bool pop(int& out)
    {
        if (q1.empty())
            return false;
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        out = q1.front();
        q1.pop();
        swap(q1, q2);
        return true;
    }
    bool isEmpty() const { return q1.empty(); }
    int top()
    {
        if (q1.empty())
            throw runtime_error("empty");
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int t = q1.front();
        q2.push(t);
        q1.pop();
        swap(q1, q2);
        return t;
    }

   private:
    queue<int> q1, q2;
};

int main()
{
    StackMultiQueue s;
    s.push(1);
    s.push(2);
    int v;
    if (s.pop(v))
        cout << v << "\n";
    cout << s.top() << "\n";
    return 0;
}

// Time Complexity: push O(1), pop/top O(n)
// Space Complexity: O(n)
