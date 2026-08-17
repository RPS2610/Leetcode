#include <queue>
using namespace std;

class RecentCounter
{
private:
    queue<int> q;

public:

    RecentCounter()
    {
    }

    int ping(int t)
    {
        // Add current request
        q.push(t);

        // Remove requests older than 3000 milliseconds
        while (q.front() < t - 3000)
        {
            q.pop();
        }

        // Number of requests in [t - 3000, t]
        return q.size();
    }
};