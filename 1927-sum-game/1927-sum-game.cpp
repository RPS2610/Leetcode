class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int diff = 0;
        int leftQ = 0, rightQ = 0;

        // Left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                diff += num[i] - '0';
        }

        // Right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                diff -= num[i] - '0';
        }

        int qDiff = rightQ - leftQ;

        // Odd difference -> Alice wins
        if (qDiff % 2 != 0)
            return true;

        // Bob wins only if equality can be forced
        return diff != 9 * (qDiff / 2);
    }
};