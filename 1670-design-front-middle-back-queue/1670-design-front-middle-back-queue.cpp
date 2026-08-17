#include <deque>
using namespace std;

class FrontMiddleBackQueue
{
private:
    deque<int> dq;

public:

    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        dq.push_front(val);
    }

    void pushMiddle(int val)
    {
        int index = dq.size() / 2;

        dq.insert(dq.begin() + index, val);
    }

    void pushBack(int val)
    {
        dq.push_back(val);
    }

    int popFront()
    {
        if (dq.empty())
        {
            return -1;
        }

        int value = dq.front();
        dq.pop_front();

        return value;
    }

    int popMiddle()
    {
        if (dq.empty())
        {
            return -1;
        }

        int index = (dq.size() - 1) / 2;

        int value = dq[index];

        dq.erase(dq.begin() + index);

        return value;
    }

    int popBack()
    {
        if (dq.empty())
        {
            return -1;
        }

        int value = dq.back();
        dq.pop_back();

        return value;
    }
};