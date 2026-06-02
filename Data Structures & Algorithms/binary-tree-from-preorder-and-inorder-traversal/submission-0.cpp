class Solution {
public:

    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder,
                    int& preIdx,
                    int inStart,
                    int inEnd,
                    unordered_map<int, int>& mp) {

        // No nodes left in this inorder range
        if (inStart > inEnd)
            return nullptr;

        // Preorder always gives the root first
        TreeNode* root = new TreeNode(preorder[preIdx++]);

        // Find root position in inorder
        int mid = mp[root->val];

        /*
            In inorder:

            [ left subtree ] root [ right subtree ]

            Everything left of 'mid' belongs to left subtree.
            Everything right of 'mid' belongs to right subtree.
        */

        // Build left subtree first because preorder is:
        // Root -> Left -> Right
        root->left = build(preorder,
                           inorder,
                           preIdx,
                           inStart,
                           mid - 1,
                           mp);

        // After left subtree is finished,
        // preorder naturally points to right subtree root
        root->right = build(preorder,
                            inorder,
                            preIdx,
                            mid + 1,
                            inEnd,
                            mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder value -> index
        // So we can find root position in O(1)
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        // Points to current root in preorder
        int preIdx = 0;

        // Initially whole inorder array represents the tree
        return build(preorder,
                     inorder,
                     preIdx,
                     0,
                     inorder.size() - 1,
                     mp);
    }
};