#include <iostream>
#include <stack>

class twoStacks
{
public:
    int *arr;
    int size;
    int top1, top2;

    twoStacks(int n = 100)
    {
        arr = new int[n];
        size = n;
        top1 = -1;
        top2 = n;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 + 1 >= top2)
        {
            // Stack1 overflow condition
            return;
        }
        arr[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        if (top2 - 1 <= top1)
        {
            // Stack2 overflow condition
            return;
        }
        arr[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
        {
            // Stack1 underflow condition
            return -1;
        }
        return arr[top1--];
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size)
        {
            // Stack2 underflow condition
            return -1;
        }
        return arr[top2++];
    }
    ~twoStacks()
    {
        delete[] arr;
    }
};

int main()
{

    twoStacks st;
    st.push1(2);
    st.push1(3);
    st.push2(4);
    st.pop1();
    st.pop2();
    st.pop2();

    std::cout << "Pop1 result: " << st.pop1() << "\n"; // Should return 2
    std::cout << "Pop2 result: " << st.pop2() << "\n"; // Should return -1 (underflow)
    std::cout << "Pop2 result: " << st.pop2() << "\n"; // Should also return -1 (underflow)

    return 0;
}