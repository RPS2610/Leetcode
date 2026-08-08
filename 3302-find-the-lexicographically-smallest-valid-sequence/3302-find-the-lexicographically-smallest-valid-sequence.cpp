class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = smallest index in word1 where word2[i...m-1]
        // can be matched exactly.
        vector<int> suf(m, -1);

        int j = n - 1;

        for (int i = m - 1; i >= 0; i--) {
            while (j >= 0 && word1[j] != word2[i]) {
                j--;
            }

            if (j < 0)
                break;

            suf[i] = j;
            j--;
        }

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        for (int i = 0; i < m; i++) {
            while (pos < n) {
                // Case 1: Characters are equal.
                if (word1[pos] == word2[i]) {
                    // We can safely choose this index.
                    ans.push_back(pos);
                    pos++;
                    break;
                }

                // Case 2: Use our one allowed mismatch.
                if (!usedMismatch) {
                    // After choosing pos as the mismatch,
                    // word2[i+1...] must match exactly.
                    if (i == m - 1 ||
                        (suf[i + 1] != -1 && suf[i + 1] > pos)) {
                        
                        ans.push_back(pos);
                        pos++;
                        usedMismatch = true;
                        break;
                    }
                }

                pos++;
            }

            // Couldn't find a valid index.
            if (ans.size() != i + 1)
                return {};
        }

        return ans;
    }
};