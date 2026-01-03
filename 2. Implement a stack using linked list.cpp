/*
 Task: Implement a stack using linked list
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    explicit Node(int v) : val(v), next(nullptr) {}
};

class LinkedListStack
{
   public:
    LinkedListStack() : head(nullptr) {}
    ~LinkedListStack()
    {
        while (head)
        {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }

    void push(int x)
    {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }
    bool pop(int& out)
    {
        if (!head)
            return false;
        out = head->val;
        Node* t = head;
        head = head->next;
        delete t;
        return true;
    }
    bool isEmpty() const { return head == nullptr; }
    int top() const
    {
        if (!head)
            throw runtime_error("empty");
        return head->val;
    }

   private:
    Node* head;
};

int main()
{
    LinkedListStack s;
    s.push(10);
    s.push(20);
    int v;
    if (s.pop(v))
        cout << v << "\n";
    cout << s.top() << "\n";
    return 0;
}

// Time Complexity: push/pop/top O(1)
// Space Complexity: O(n)
