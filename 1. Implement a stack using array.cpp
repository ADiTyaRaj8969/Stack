/*
 Task: Implement a stack using array
*/

#include <bits/stdc++.h>
using namespace std;

class ArrayStack
{
   public:
    explicit ArrayStack(size_t capacity) : data(new int[capacity]), cap(capacity), top_idx(-1) {}

    ~ArrayStack() { delete[] data; }

    bool push(int x)
    {
        if (static_cast<size_t>(top_idx + 1) >= cap)
            return false;
        data[++top_idx] = x;
        return true;
    }

    bool pop(int& out)
    {
        if (top_idx < 0)
            return false;
        out = data[top_idx--];
        return true;
    }

    bool isEmpty() const { return top_idx < 0; }

    int top() const
    {
        if (top_idx < 0)
            throw runtime_error("empty");
        return data[top_idx];
    }

   private:
    int* data;
    size_t cap;
    int top_idx;
};

int main()
{
    ArrayStack s(10);
    s.push(1);
    s.push(2);
    int v;
    if (s.pop(v))
        cout << v << "\n";
    cout << s.top() << "\n";
    return 0;
}

// Time Complexity: push/pop/top O(1)
// Space Complexity: O(n)
