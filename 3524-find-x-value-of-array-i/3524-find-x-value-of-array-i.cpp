class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at previous position
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            int val = num % k;

            // Start a new subarray with nums[i]
            ndp[val]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * val) % k;
                ndp[newR] += dp[r];
            }

            dp = ndp;

            // Add all subarrays ending at current position
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};