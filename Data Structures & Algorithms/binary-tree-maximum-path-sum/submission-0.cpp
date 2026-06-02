class Solution {
public:
    int ans = INT_MIN;  // Stores the maximum path sum found anywhere in the tree

    int dfs(TreeNode* root) {
        if (!root) return 0;  // Null node contributes nothing

        // Get best path sum coming from left/right subtree.
        // Ignore negative paths because they only reduce the sum.
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Path passing through current node:
        // left branch + current node + right branch
        // This path CANNOT be returned upward because it uses both sides.
        ans = max(ans, left + right + root->val);

        // Return the best SINGLE branch that can be extended by parent.
        // Parent can choose either left side or right side, not both.
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);      // Traverse entire tree and update ans
        return ans;     // Return maximum path found
    }
};