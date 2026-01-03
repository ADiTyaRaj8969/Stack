/*
 Task: Implement a stack using two queues
*/

#include <bits/stdc++.h>
using namespace std;

class StackUsingQueues
{
   public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    bool pop(int& out)
    {
        if (q1.empty())
            return false;
        out = q1.front();
        q1.pop();
        return true;
    }
    bool isEmpty() const { return q1.empty(); }
    int top() const
    {
        if (q1.empty())
            throw runtime_error("empty");
        return q1.front();
    }

   private:
    queue<int> q1, q2;
};

int main()
{
    StackUsingQueues s;
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
