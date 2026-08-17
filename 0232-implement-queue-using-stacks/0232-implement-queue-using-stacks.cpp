#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> stack1;
    stack<int> stack2;

public:

    MyQueue()
    {
    }

    void push(int x)
    {
        stack1.push(x);
    }

    int pop()
    {
        // Transfer elements if stack2 is empty
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int value = stack2.top();
        stack2.pop();

        return value;
    }

    int peek()
    {
        // Transfer elements if stack2 is empty
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }

    bool empty()
    {
        return stack1.empty() && stack2.empty();
    }
};