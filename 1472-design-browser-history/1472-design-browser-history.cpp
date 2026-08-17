class BrowserHistory
{
private:
    vector<string> history;
    int current;

public:
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        current = 0;
    }

    void visit(string url)
    {
        // Remove forward history
        history.resize(current + 1);

        // Add new URL
        history.push_back(url);

        // Move to new page
        current++;
    }

    string back(int steps)
    {
        current = max(0, current - steps);

        return history[current];
    }

    string forward(int steps)
    {
        current = min((int)history.size() - 1, current + steps);

        return history[current];
    }
};