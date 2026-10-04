class Solution {
public:
    int guessNumber(int n) {
        long long low = 1, high = n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int result = guess(mid);

            if (result == 0)
                return mid;
            else if (result == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};