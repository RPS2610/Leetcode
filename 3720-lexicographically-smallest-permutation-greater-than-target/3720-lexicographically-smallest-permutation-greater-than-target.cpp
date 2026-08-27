class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        // Count characters of s
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string ans = "";
        
        for (int i = 0; i < target.size(); i++) {

            // Try to put the same character as target[i]
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                ans += target[i];
                cnt[x]--;
            }
            else {
                // Cannot continue with same character.
                // Find a bigger character.
                int bigger = -1;

                for (int j = x + 1; j < 26; j++) {
                    if (cnt[j] > 0) {
                        bigger = j;
                        break;
                    }
                }

                if (bigger != -1) {
                    ans += char('a' + bigger);
                    cnt[bigger]--;

                    // Put remaining characters in smallest order
                    for (int j = 0; j < 26; j++) {
                        while (cnt[j] > 0) {
                            ans += char('a' + j);
                            cnt[j]--;
                        }
                    }

                    return ans;
                }

                // We need to go back and increase an earlier character.
                while (!ans.empty()) {
                    int last = ans.back() - 'a';
                    ans.pop_back();
                    cnt[last]++;

                    int greater = -1;

                    for (int j = last + 1; j < 26; j++) {
                        if (cnt[j] > 0) {
                            greater = j;
                            break;
                        }
                    }

                    if (greater != -1) {
                        ans += char('a' + greater);
                        cnt[greater]--;

                        for (int j = 0; j < 26; j++) {
                            while (cnt[j] > 0) {
                                ans += char('a' + j);
                                cnt[j]--;
                            }
                        }

                        return ans;
                    }
                }

                return "";
            }
        }

        // s itself formed exactly target.
        // We need something strictly greater.
        while (!ans.empty()) {
            int last = ans.back() - 'a';
            ans.pop_back();
            cnt[last]++;

            int greater = -1;

            for (int j = last + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    greater = j;
                    break;
                }
            }

            if (greater != -1) {
                ans += char('a' + greater);
                cnt[greater]--;

                for (int j = 0; j < 26; j++) {
                    while (cnt[j] > 0) {
                        ans += char('a' + j);
                        cnt[j]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};