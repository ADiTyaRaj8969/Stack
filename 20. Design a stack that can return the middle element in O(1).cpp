/*
 Task: Design a stack that can return the middle element in O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Use a doubly linked list with a pointer to middle
struct DLLNode
{
    int val;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class MidStack
{
   public:
    MidStack() : head(nullptr), mid(nullptr), sz(0) {}

    void push(int x)
    {
        DLLNode* n = new DLLNode(x);
        n->next = head;
        if (head)
            head->prev = n;
        head = n;
        ++sz;
        if (sz == 1)
            mid = n;
        else if (sz % 2 == 0)
            mid = mid->prev;  // move mid back when size becomes even
    }

    bool pop(int& out)
    {
        if (!head)
            return false;
        out = head->val;
        DLLNode* t = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete t;
        --sz;
        if (sz == 0)
            mid = nullptr;
        else if (sz % 2 == 1)
            mid = mid->next;  // move mid forward when size becomes odd
        return true;
    }

    int findMiddle() const
    {
        if (!mid)
            throw runtime_error("empty");
        return mid->val;
    }

    bool deleteMiddle(int& out)
    {
        if (!mid)
            return false;
        out = mid->val;
        DLLNode* m = mid;
        if (m->prev)
            m->prev->next = m->next;
        if (m->next)
            m->next->prev = m->prev;
        if (m == head)
            head = m->next;
        delete m;
        --sz;
        if (sz == 0)
        {
            mid = nullptr;
        }
        else if (sz % 2 == 0)
            mid = head ? head : nullptr;  // recompute approx: move to previous of old mid isn't
                                          // available; instead adjust
        else
            mid = head;  // finalize
        // For simplicity after deletion, recompute exact middle in O(n) worst-case; in practice
        // keep pointer updates to O(1)
        DLLNode* cur = head;
        int idx = 0, target = sz / 2;
        while (cur && idx < target)
        {
            cur = cur->next;
            ++idx;
        }
        mid = cur;
        return true;
    }

    bool empty() const { return sz == 0; }
    int size() const { return sz; }

   private:
    DLLNode* head;
    DLLNode* mid;
    int sz;
};

int main()
{
    MidStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "middle: " << s.findMiddle() << "\n";
    int v;
    s.deleteMiddle(v);
    cout << "deleted: " << v << " new middle: " << s.findMiddle() << "\n";
    return 0;
}

// Time Complexity: push/pop/findMiddle O(1) (deleteMiddle uses recompute step here O(n) to be safe)
// Space Complexity: O(n)
