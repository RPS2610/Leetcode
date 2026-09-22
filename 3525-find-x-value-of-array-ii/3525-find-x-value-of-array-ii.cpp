class Solution {
public:
    struct Node {
        int prod;
        int pref[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                pref[i] = 0;
        }
    };

    int n, k;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node c;

        c.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < k; i++)
            c.pref[i] += a.pref[i];

        for (int i = 0; i < k; i++) {
            int r = (a.prod * i) % k;
            c.pref[r] += b.pref[i];
        }

        return c;
    }

    void update(int pos, int val) {
        pos += n;

        tree[pos] = Node();
        int r = val % k;
        tree[pos].prod = r;
        tree[pos].pref[r] = 1;

        pos /= 2;

        while (pos) {
            tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
            pos /= 2;
        }
    }

    Node query(int l, int r) {
        Node left, right;

        l += n;
        r += n;

        while (l <= r) {
            if (l % 2 == 1)
                left = merge(left, tree[l++]);

            if (r % 2 == 0)
                right = merge(tree[r--], right);

            l /= 2;
            r /= 2;
        }

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {
        n = nums.size();
        k = K;

        tree.resize(2 * n);

        for (int i = 0; i < n; i++) {
            int r = nums[i] % k;
            tree[n + i].prod = r;
            tree[n + i].pref[r] = 1;
        }

        for (int i = n - 1; i > 0; i--)
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;
            update(index, value);

            Node res = query(start, n - 1);

            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};