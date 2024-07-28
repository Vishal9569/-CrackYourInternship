#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;

        // Push all persons onto the stack
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        // Find the potential celebrity
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (M[a][b])
            {
                // a knows b, so a cannot be a celebrity
                st.push(b);
            }
            else
            {
                // a does not know b, so b cannot be a celebrity
                st.push(a);
            }
        }

        if (st.empty())
        {
            return -1; // No celebrity found
        }

        // The potential celebrity
        int candidate = st.top();
        st.pop();

        // Verify the candidate
        int rowSum = 0;
        int colSum = 0;
        for (int i = 0; i < n; i++)
        {
            rowSum += M[candidate][i];
            colSum += M[i][candidate];
        }

        // Check if the candidate is known by everyone and knows no one
        if (rowSum == 0 && colSum == n - 1)
        {
            return candidate;
        }
        else
        {
            return -1;
        }
    }

    // Dual Stack Implementation
    int *arr;
    int size;
    int top1, top2;

    Solution(int n = 100)
    {
        arr = new int[n];
        size = n;
        top1 = -1;
        top2 = n;
    }

    // Function to push an integer into stack1.
    void push1(int x)
    {
        if (top1 + 1 >= top2)
        {
            // Stack1 overflow condition
            cout << "Stack1 overflow\n";
            return;
        }
        arr[++top1] = x;
    }

    // Function to push an integer into stack2.
    void push2(int x)
    {
        if (top2 - 1 <= top1)
        {
            // Stack2 overflow condition
            cout << "Stack2 overflow\n";
            return;
        }
        arr[--top2] = x;
    }

    // Function to remove an element from top of stack1.
    int pop1()
    {
        if (top1 == -1)
        {
            // Stack1 underflow condition
            cout << "Stack1 underflow\n";
            return -1;
        }
        return arr[top1--];
    }

    // Function to remove an element from top of stack2.
    int pop2()
    {
        if (top2 == size)
        {
            // Stack2 underflow condition
            cout << "Stack2 underflow\n";
            return -1;
        }
        return arr[top2++];
    }

    ~Solution()
    {
        delete[] arr;
    }
};

int main()
{
    // Demonstration of the celebrity problem
    Solution solution;
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}};
    int n = 3;
    int celeb = solution.celebrity(M, n);
    if (celeb != -1)
    {
        cout << "The celebrity is person " << celeb << endl;
    }
    else
    {
        cout << "No celebrity found" << endl;
    }

    // Demonstration of dual stack
    Solution dualStack(10);
    dualStack.push1(1);
    dualStack.push1(2);
    dualStack.push2(3);
    dualStack.push2(4);

    cout << "Popped from stack1: " << dualStack.pop1() << endl;
    cout << "Popped from stack2: " << dualStack.pop2() << endl;

    return 0;
};
