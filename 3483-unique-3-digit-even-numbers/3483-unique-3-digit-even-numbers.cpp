class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {0};

        // Count frequency of each digit
        for (int x : digits) {
            count[x]++;
        }

        int ans = 0;

        // Check every 3-digit number
        for (int num = 100; num <= 999; num++) {

            // Number must be even
            if (num % 2 != 0)
                continue;

            int x = num;

            int a = x % 10;
            x /= 10;

            int b = x % 10;
            x /= 10;

            int c = x % 10;

            // Check if required digits are available
            count[a]--;
            count[b]--;
            count[c]--;

            if (count[a] >= 0 && count[b] >= 0 && count[c] >= 0) {
                ans++;
            }

            // Restore counts
            count[a]++;
            count[b]++;
            count[c]++;
        }

        return ans;
    }
};