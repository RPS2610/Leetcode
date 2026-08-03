class RangeModule {
private:
    map<int, int> intervals;

public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        auto it = intervals.lower_bound(left);

        if (it != intervals.begin()) {
            --it;
            if (it->second < left)
                ++it;
        }

        while (it != intervals.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            it = intervals.erase(it);
        }

        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);

        if (it == intervals.begin())
            return false;

        --it;

        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = intervals.lower_bound(left);

        if (it != intervals.begin()) {
            --it;
            if (it->second <= left)
                ++it;
        }

        vector<pair<int, int>> temp;

        while (it != intervals.end() && it->first < right) {
            if (it->first < left)
                temp.push_back({it->first, left});

            if (it->second > right)
                temp.push_back({right, it->second});

            it = intervals.erase(it);
        }

        for (auto &p : temp)
            intervals[p.first] = p.second;
    }
};