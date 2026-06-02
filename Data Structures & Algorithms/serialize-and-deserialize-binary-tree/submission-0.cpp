/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Serialize tree -> string
    string serialize(TreeNode* root) {

        if (!root)
            return "N,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Helper function used during deserialization
    TreeNode* build(vector<string>& nodes, int& i) {

        // Null node found
        if (nodes[i] == "N") {
            i++;
            return nullptr;
        }

        // Create current node
        TreeNode* root = new TreeNode(stoi(nodes[i++]));

        // Build left subtree
        root->left = build(nodes, i);

        // Build right subtree
        root->right = build(nodes, i);

        return root;
    }

    // Deserialize string -> tree
    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string curr;

        // Split string using ','
        for (char c : data) {

            if (c == ',') {
                nodes.push_back(curr);
                curr.clear();
            }
            else {
                curr += c;
            }
        }

        int i = 0;
        return build(nodes, i);
    }
};