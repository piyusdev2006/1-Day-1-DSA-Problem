/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* dfs(TreeNode* root, unordered_set<int>& deleteSet,
                  vector<TreeNode*>& forest) {
        if (root == nullptr)
            return nullptr; // Base Case

        // Step 1: Bottom-up processing (Post-order traversal)
        root->left = dfs(root->left, deleteSet, forest);
        root->right = dfs(root->right, deleteSet, forest);

        // Step 2: Check agar current node ko delete karna hai
        if (deleteSet.count(root->val)) {
            // Agar iske children hain, toh woh naye trees ke roots banenge
            if (root->left != nullptr)
                forest.push_back(root->left);
            if (root->right != nullptr)
                forest.push_back(root->right);

            // Parent ko batao ki main ab delete ho chuka hu, isliye nullptr
            // return karo
            return nullptr;
        }

        // Agar node delete nahi hua, toh return original root pointer
        return root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> deleteSet(to_delete.begin(), to_delete.end());

        // Agar main root node khud delete nahi ho raha, toh woh forest ka hissa
        // hoga
        if (dfs(root, deleteSet, forest) != nullptr) {
            forest.push_back(root);
        }

        return forest;
    }
};