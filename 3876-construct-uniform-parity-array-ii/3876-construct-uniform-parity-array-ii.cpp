class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        // If all numbers are already even
        bool allEven = true;

        for (int x : nums1) {
            if (x % 2 != 0) {
                allEven = false;
                break;
            }
        }

        if (allEven)
            return true;

        // If minimum is odd, every larger even number
        // can subtract it and become odd.
        return mn % 2 == 1;
    }
};