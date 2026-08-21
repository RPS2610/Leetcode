class Solution {
public:
    using ll = long long;

    ll gcdll(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return a / gcdll(a, b) * b;
    }

    // Count distinct valid amounts <= x
    ll countAmounts(ll x, vector<int>& coins) {
        int n = coins.size();
        ll count = 0;

        // Inclusion-exclusion
        for (int mask = 1; mask < (1 << n); mask++) {
            ll multiple = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    multiple = lcm(multiple, coins[i]);

                    if (multiple > x) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow)
                continue;

            ll add = x / multiple;

            if (bits % 2 == 1)
                count += add;
            else
                count -= add;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll low = 1;
        ll high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};