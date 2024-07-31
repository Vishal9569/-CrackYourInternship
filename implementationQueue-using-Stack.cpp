#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    stack<int> s1; // stack for push operations
    stack<int> s2; // stack for pop operations

    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
        cout << "pushed :" << x << endl;
    }

    int pop()
    {
        if (empty())
            return 0;

        if (!s2.empty())
        {
            int ele = s2.top();
            s2.pop();
            cout << "poped : " << s2.top() << endl;
            return ele;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                cout << "poped: " << s1.top() << endl;
                s1.pop();
            }
            int ele = s2.top();
            s2.pop();
            return ele;
        }
    }

    int peek()
    {
        if (empty())
            return 0;

        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int ele = s2.top();
            cout << "peek : " << ele << endl;
            // s2.pop(); // No need to pop here for peek operation
            return ele;
        }
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue q;

    q.push(1);
    q.push(2);
    q.peek();
    q.pop();
    q.empty();
}