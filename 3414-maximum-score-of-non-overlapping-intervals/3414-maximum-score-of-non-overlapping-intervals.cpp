class Solution {
public:
    struct Node {
        int l, r, w, idx;
    };

    struct Result {
        long long score;
        vector<int> ids;
    };

    vector<Node> a;
    vector<int> nxt;
    vector<vector<Result>> dp;
    int n;

    bool better(Result a, Result b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    Result solve(int i, int k) {
        if (i == n || k == 0)
            return {0, {}};

        if (dp[i][k].score != -1)
            return dp[i][k];

        Result skip = solve(i + 1, k);

        Result take = solve(nxt[i], k - 1);
        take.score += a[i].w;
        take.ids.push_back(a[i].idx);

        sort(take.ids.begin(), take.ids.end());

        if (better(take, skip))
            return dp[i][k] = take;

        return dp[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        a.resize(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](Node x, Node y) {
            return x.l < y.l;
        });

        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i].l;

        nxt.resize(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i].r
            ) - starts.begin();
        }

        dp.assign(n, vector<Result>(5, {-1, {}}));

        return solve(0, 4).ids;
    }
};