class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string ans = "";
        string hex = "0123456789abcdef";

        unsigned int n = num;

        while (n > 0) {
            ans = hex[n % 16] + ans;
            n /= 16;
        }

        return ans;
    }
};