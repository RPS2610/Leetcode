class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        vector<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push_back(curr);
                curr = curr->left;
            }

            curr = st.back();
            st.pop_back();

            ans.push_back(curr->val);

            curr = curr->right;
        }

        return ans;
    }
};