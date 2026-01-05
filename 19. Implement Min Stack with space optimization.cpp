/*
 Task: Implement Min Stack with space optimization
*/

#include <bits/stdc++.h>
using namespace std;

// Store differences to reduce extra stack space:
// https://stackoverflow.com/questions/1603095/how-to-implement-a-stack-with-getmin
class MinStackOpt
{
   public:
    void push(long long x)
    {
        if (st.empty())
        {
            st.push(x);
            minVal = x;
        }
        else
        {
            if (x < minVal)
            {
                st.push(2 * x - minVal);
                minVal = x;
            }
            else
                st.push(x);
        }
    }
    bool pop(long long& out)
    {
        if (st.empty())
            return false;
        long long t = st.top();
        st.pop();
        if (t < minVal)
        {
            out = minVal;
            minVal = 2 * minVal - t;
        }
        else
            out = t;
        return true;
    }
    long long top()
    {
        if (st.empty())
            throw runtime_error("empty");
        long long t = st.top();
        return (t < minVal) ? minVal : t;
    }
    long long getMin()
    {
        if (st.empty())
            throw runtime_error("empty");
        return minVal;
    }
    bool empty() const { return st.empty(); }

   private:
    stack<long long> st;
    long long minVal;
};

int main()
{
    MinStackOpt ms;
    ms.push(3);
    ms.push(2);
    ms.push(1);
    cout << ms.getMin() << "\n";
    long long v;
    ms.pop(v);
    cout << ms.getMin() << "\n";
    return 0;
}

// Time Complexity: push/pop/top/getMin O(1)
// Space Complexity: O(n) but optimized
